#include <Arduino.h>
#include <Adafruit_BMP280.h>
#include <sensors/accelerometer.h>
#include <sensors/gyroscope.h>
#include <sensors/magnetometer.h>

#include "detect.h"

const float SEA_LEVEL_HPA = 1017.2; // Adjust to local forecast

Adafruit_BMP280 barometer;
accelerometer accelerometer;
gyroscope gyroscope;
magnetometer magnetometer;

enum State {
    ASCENT,
    DESCENT,
    RECOVERY
};

State state = ASCENT;

void testLoop() {
    Serial.print(F("Temperature = "));
    Serial.print(barometer.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(barometer.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(barometer.readAltitude(SEA_LEVEL_HPA));
    Serial.println(" m");

    bma2x2_accel_data accelData{};
    accelerometer.read(&accelData);
    Serial.print(F("Accel X = "));
    Serial.print(accelData.x);
    Serial.print(F( ", Y = "));
    Serial.print(accelData.y);
    Serial.print(F(", Z = "));
    Serial.println(accelData.z);

    bmg160_data_t gyroData{};
    gyroscope.read(&gyroData);
    Serial.print(F("Gyro X = "));
    Serial.print(gyroData.datax);
    Serial.print(F( ", Y = "));
    Serial.print(gyroData.datay);
    Serial.print(F(", Z = "));
    Serial.println(gyroData.dataz);

    bmm150_mag_data magData{};
    magnetometer.read(&magData);
    Serial.print(F("Mag X = "));
    Serial.print(magData.x);
    Serial.print(F( ", Y = "));
    Serial.print(magData.y);
    Serial.print(F(", Z = "));
    Serial.println(magData.z);

    Serial.println();
    delay(2000);
}

void parachuteLoop() {
    float currentAltitude = barometer.readAltitude(SEA_LEVEL_HPA);
    Serial.print(currentAltitude);

    switch (state) {
        case ASCENT:
            if (isPastApogee(currentAltitude))
                state = DESCENT;
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

    if (!barometer.begin() || !accelerometer.init() || gyroscope.init() || magnetometer.init()) {
        Serial.println(F("Failed to init one of the sensors"));
        while (true);
    }
}

void loop() {
    testLoop();
    // parachuteLoop();
}
