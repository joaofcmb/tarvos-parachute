#include "gyroscope.h"

bool gyroscope::init() {
    int comResult = (u8) bmg160_init(&bmg160);
    comResult += bmg160_set_power_mode(BMG160_MODE_NORMAL);

    return comResult == BMG160_INIT_VALUE;
}

bool gyroscope::stop() {
    return bmg160_set_power_mode(BMG160_MODE_DEEPSUSPEND) == BMG160_INIT_VALUE;
}

bool gyroscope::read(bmg160_data_t *gyroData) {
    return bmg160_get_data_xyz(gyroData) == BMG160_INIT_VALUE;
}
