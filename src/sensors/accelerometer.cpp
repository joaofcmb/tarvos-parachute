#include "accelerometer.h"

bool accelerometer::init() {
    int comResult = (u8) bma2x2_init(&bma2x2);
    comResult += bma2x2_set_power_mode(BMA2x2_MODE_NORMAL);

    return comResult == SUCCESS;
}

bool accelerometer::stop() {
    return bma2x2_set_power_mode(BMA2x2_MODE_DEEP_SUSPEND) == SUCCESS;
}

bool accelerometer::read(bma2x2_accel_data *accelData) {
    return bma2x2_read_accel_xyz(accelData) == SUCCESS;
}
