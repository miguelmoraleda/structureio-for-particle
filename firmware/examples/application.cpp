#include "application.h"
#include "Structureioforspark/Structureioforspark.h"

/**
* Declaring the variables.
*/
unsigned int nextTime = 0;    // Next time to contact the server
Structureioforspark structure;

// Structure credentials.
const char* STRUCTURE_DEVICE_ID = "my-device-id";
const char* STRUCTURE_ACCESS_KEY = "my-app-key";
const char* STRUCTURE_ACCESS_SECRET = "my-app-secret";

StructureDevice device(STRUCTURE_DEVICE_ID);

void connect() {
  device.connectSecure(wifiClient, STRUCTURE_ACCESS_KEY, STRUCTURE_ACCESS_SECRET);

  while(!device.connected()) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected!");
}

void setup() {
    Serial.begin(9600);

    while(!Serial) { }

    connect();

}

void loop() {
  bool toReconnect = false;

  if(!device.connected()) {
    Serial.println("Disconnected from Structure");
    toReconnect = true;
  }

  if(toReconnect) {
    connect();
  }

  device.loop();
}
