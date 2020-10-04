#ifndef TARVOS_ACCELEROMETER_H
#define TARVOS_ACCELEROMETER_H

#include "sensor.h"
#include "../../lib/BMA2x2_driver-bma2x2_2.0.8/bma2x2.h"

class accelerometer: public sensor {
private:
    struct bma2x2_t bma2x2{};

public:
    bool init() override;
    bool stop() override;
    bool read(bma2x2_accel_data *accelData);
};


#endif //TARVOS_ACCELEROMETER_H
