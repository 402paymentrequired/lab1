// default arduino library
#include <Arduino.h>

// crypto library
#include <SHA256.h>

// I2C cap touch lib
#include <Wire.h>
#include "Adafruit_MPR121.h"

// RF library
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Radio
RF24 radio(3, 2);
const byte address[6] = "00001";
const char pass = 0xFF;
const char fail = 0x00;

// Cap touch
Adafruit_MPR121 cap = Adafruit_MPR121();
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

// Crypto
SHA256 hash;
const char* key = "super secret key";

// setup()

  
int main() {

  // Radio
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  char responsecode;
  byte challenge[32];
  byte response[32];
  byte hmac[32];

  // Cap touch
  while (!Serial);   // needed to keep leonardo/micro from starting too fast
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");


  // Control
  int state = 1; // implemented as a finite-state machine
  long timeout_time;
  long light_expire_time = 0;
  bool is_button_pressed = false;

  while(true) {

    currtouched = cap.touched();

    for (uint8_t i=0; i<12; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
      if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
        Serial.print(i); Serial.println(" touched");
        is_button_pressed = true;
      }
      // if it *was* touched and now *isnt*, alert!
      if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
        Serial.print(i); Serial.println(" released");
        is_button_pressed = false;
      }
    }

    // reset our state
    lasttouched = currtouched;

    // todo: set is_button_pressed

    // Button
    if(is_button_pressed == false) {
      state = 0;
    }

    // button is pressed; send request
    if(is_button_pressed && state == 0) {
      // write request
      radio.openWritingPipe(address);
      radio.stopListening();
      radio.write(&pass, sizeof(pass));
      
      // listen for response
      radio.openReadingPipe(0, address);
      radio.startListening();

      state = 2;
      // compute timeout time
      timeout_time = millis() + 250;
    }

    // Listen for challenge
    if(state == 2) {
      if(millis() < timeout_time) {
        if(radio.available()) {
          radio.read(&challenge, sizeof(challenge));
          state = 3;
        }
      }
      else {
        state = 0;
      }
    }

    // reject challenge if potentially malicious
    if(state == 3) {
      
      // rainbow table server spoofing defense
      int index_00 = 0;
      int index_ff = 0;
      for(int i=0; i<32; i++) {
        if(challenge[i] == 0x00) {
          index_00 += 1;
        }
        if(challenge[i] == 0xFF) {
          index_00 += 1;
        }
      }
      // reject challenges of 0x00...00 or 0xFF...FF
      if(index_00 == 32 || index_ff == 32) {
        state = 0;
      }

      // otherwise, compute the hash.
      else {
        state = 4;
      }
    }

    // Compute response
    if(state == 4) {
      hash.resetHMAC(key, sizeof(key));
      hash.update(challenge, sizeof(challenge));
      hash.finalizeHMAC(key, sizeof(key), hmac, sizeof(hmac));
      state = 5;
    }

    // Send response
    if(state == 5) {
      radio.openWritingPipe(address);
      radio.stopListening();
      radio.write(&hmac, sizeof(hmac));

      state = 6;

      // set up timeout
      timeout_time = millis() + 250;

      // set up reading
      radio.openReadingPipe(0, address);
      radio.startListening();
    }

    // Listen for response
    if(state == 6) {
      if(millis() < timeout_time) {
        if(radio.available()) {
          radio.read(&responsecode, sizeof(responsecode));
          if(responsecode == pass) {
            state = 7;
            timeout_time = millis() + 500;
          }
          else {
            state = 0;
          }
        }
      }
      else {
        state = 0;
      }
    }

    // The light is on!
    if(state == 7) {
      if(millis() > timeout_time) {
        state = 0;
      }
    }

    delay(50);

  }
}
