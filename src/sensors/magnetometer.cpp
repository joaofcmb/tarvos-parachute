#include "magnetometer.h"

bool magnetometer::init() {
    struct bmm150_settings settings{.pwr_mode = BMM150_POWERMODE_NORMAL, .preset_mode = BMM150_PRESETMODE_REGULAR};

    int comResult = (unsigned char) bmm150_init(&dev);
    comResult += bmm150_set_op_mode(&settings, &dev);
    comResult += bmm150_set_presetmode(&settings, &dev);

    return comResult == BMM150_OK;
}

bool magnetometer::stop() {
    struct bmm150_settings settings{.pwr_mode = BMM150_POWERMODE_SUSPEND, .preset_mode = BMM150_PRESETMODE_LOWPOWER};

    int comResult = (unsigned char) bmm150_set_op_mode(&settings, &dev);
    comResult += bmm150_set_presetmode(&settings, &dev);

    return comResult == BMM150_OK;
}

bool magnetometer::read(bmm150_mag_data *magData) {
    return bmm150_read_mag_data(magData, &dev) == BMM150_OK;
}
