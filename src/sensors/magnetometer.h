#ifndef TARVOS_MAGNETOMETER_H
#define TARVOS_MAGNETOMETER_H

#include "sensor.h"
#include "../../lib/BMM150-Sensor-API-bmm150_v2.0.0/bmm150.h"
#include "../../lib/BMM150-Sensor-API-bmm150_v2.0.0/bmm150_defs.h"

class magnetometer: sensor {
private:
    struct bmm150_dev dev{};
public:
    bool init() override;
    bool stop() override;
    bool read(bmm150_mag_data *magData);
};

#endif //TARVOS_MAGNETOMETER_H
