#include "application.h"
#include "Structureioforspark/Structureioforspark.h"

/**
* Declaring the variables.
*/
unsigned int nextTime = 0;    // Next time to contact the server
Structureioforspark structure;


void setup() {
    Serial.begin(9600);
}

void loop() {
    if (nextTime > millis()) {
        return;
    }

    Serial.println();
    Serial.println("Application>\tStart of Loop.");

    nextTime = millis() + 10000;
}
