// default arduino library
#include <Arduino.h>

// crypto library
#include <TransistorNoiseSource.h>
#include <SHA256.h>
#include <RNG.h>

// RF library
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Radio
RF24 radio(3, 2);
const byte address[6] = "00001";
const char pass = 0xFF;
const char fail = 0x00;

// Crypto
TransistorNoiseSource noise(A1);
SHA256 hash;
const char* key = "super secret key";

int main() {

  // Radio
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  char responsecode;
  byte challenge[32];
  byte response[32];
  byte hmac[32];

  // Crypto
  RNG.begin("Secure Button", 500);
  RNG.addNoiseSource(noise);
  hash = SHA256();
    
  // Control
  int state = 1; // implemented as a finite-state machine
  long timeout_time;
  long light_expire_time = 0;

  while(true) {

      // check for message
      if(state == 1) {
        if(radio.available()) {
          radio.read(&responsecode, sizeof(responsecode));
          if(responsecode == pass) {
            state = 2;
          }
        }
      }

      // generate challenge
      else if(state == 2) {
        RNG.rand(challenge, sizeof(challenge));
        state = 3;
      }

      // send challenge
      else if(state == 3) {
          // write challenge
          radio.openWritingPipe(address);
          radio.stopListening();
          radio.write(&challenge, sizeof(challenge));

          // reopen read pipe
          radio.openReadingPipe(0, address);
          radio.startListening();

          state = 4;
          // compute timeout time
          long timeout_time = millis() + 250;
      }

      // listen for response
      else if(state == 4) {
        if(millis() < timeout_time) {
          // get response
          if(radio.available()) {
            radio.read(&response, sizeof(response));
            state = 5;
          }
        }
        // timeout
        else {
          state = 1;
        }
      }

      // verify response
      else if(state == 5) {
        hash.resetHMAC(key, sizeof(key));
        hash.update(challenge, sizeof(challenge));
        hash.finalizeHMAC(key, sizeof(key), hmac, sizeof(hmac));

        bool pass = true;
        for(int i=0; i<32; i++) {
          if(hmac[i] != response[i]) {
            pass = false;
          }
        }

        if(pass) {
          state == 6;
        }
        else {
          state == -6;
        }
      }

      // send pass
      else if(state == 6) {
        radio.openWritingPipe(address);
        radio.stopListening();
        radio.write(&pass, sizeof(pass));
        state = 7;
      }

      // send fail
      else if(state == -6) {
        radio.openWritingPipe(address);
        radio.stopListening();
        radio.write(&fail, sizeof(fail));
        state = 1;        
      }

      // turn on light
      else if(state == 7) {
        light_expire_time = millis() + 1000;
        radio.openReadingPipe(0, address);
        radio.startListening();        
        state = 1;
      }

    if(millis() < light_expire_time) {
      // todo: turn the light on
    }

    // stir the RNG
    RNG.loop();

  }
}
