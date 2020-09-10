#include <Arduino.h>
#include <cfloat>

#include "detect.h"

// Altitude Delta

// Minimum difference between max altitude and current altitude to consider past apogee
const float ALTITUDE_DELTA = 0;

float maxAltitude = FLT_MIN;

bool isPastApogee(float currentAltitude) {
    bool pastApogee = maxAltitude - currentAltitude > ALTITUDE_DELTA;
    maxAltitude = max(maxAltitude, currentAltitude);
    return pastApogee;
}

// Average of last K altitudes Delta
/*const unsigned int K = 10;

float altitudes[K];
unsigned int i = 0;
bool pastKAltitudes = false;

void updateAltitudes(float currentAltitude) {
    altitudes[i++] = currentAltitude;

    if (!pastKAltitudes && i >= K)
        pastKAltitudes = true;

    i %= K;
}

// Minimum difference between max average and current average to consider past apogee
const double AVERAGE_DELTA = 0

double maxAverage = DBL_MIN;

bool isPastApogee(float currentAltitude) {
    updateAltitudes(currentAltitude);

    if (pastKAltitudes) {
        float sum = 0.0;
        for (float altitude : altitudes) {
            sum += altitude;
        }

        double average = sum / K;
        Serial.print(F("Average:"));
        Serial.println(average);

        bool pastApogee = maxAverage - average > AVERAGE_DELTA;
        maxAverage = max(maxAverage, average);
        return pastApogee;
    }

    return false;
}*/
