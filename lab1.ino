#include <Crypto.h>
#include <RNG.h>
#include <TransistorNoiseSource.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Radio
RF24 radio(3, 2);
const byte address[6] = "00001";

// Crypto
TransistorNoiseSource noise(A1);
const char * key = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

void setup() {
  // Radio
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  // Crypto
  RNG.begin("MyApp 1.0", 500);

}

void loop() {

  byte challenge[32];

  RNG.addNoiseSource(noise);

  RNG.rand(challenge, sizeof(challenge));

  if (radio.available()) {
    char text[32];
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }

  

}
