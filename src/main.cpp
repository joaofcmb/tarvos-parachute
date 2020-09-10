#include <Arduino.h>
#include <Adafruit_BMP280.h>

#include "detect.h"

const float SEA_LEVEL_HPA = 1017.2; // Adjust to local forecast

Adafruit_BMP280 bmp280;

enum State {
    ASCENT,
    DESCENT,
    RECOVERY
};

State state = ASCENT;

void testLoop() {
    Serial.print(F("Temperature = "));
    Serial.print(bmp280.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp280.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp280.readAltitude(SEA_LEVEL_HPA));
    Serial.println(" m");

    Serial.println();
    delay(2000);
}

void parachuteLoop() {
    float currentAltitude = bmp280.readAltitude(SEA_LEVEL_HPA);
    Serial.print(currentAltitude);

    switch (state) {
        case ASCENT:
            if (isPastApogee(currentAltitude)) {
                state = DESCENT;
            }
            break;
        case DESCENT:
            // TODO - Trigger Parachute
            Serial.println(F("Parachute Triggered"));

            state = RECOVERY;
            break;
        case RECOVERY:
            break;
    }
}

void setup() {
    Serial.begin(9600);

    if (!bmp280.begin()) {
        Serial.println(F("Failed to init the BMP280 sensor"));
        while (true);
    }
}

void loop() {
    testLoop();
    // parachuteLoop();
}
