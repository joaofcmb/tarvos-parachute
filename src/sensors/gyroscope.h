#ifndef TARVOS_GYROSCOPE_H
#define TARVOS_GYROSCOPE_H

#include "sensor.h"
#include "../../lib/BMG160_driver-bmg160_v2.0.12/bmg160.h"

class gyroscope: public sensor {
private:
    struct bmg160_t bmg160{};
public:
    bool init() override;
    bool stop() override;
    bool read(bmg160_data_t *gyroData);
};


#endif //TARVOS_GYROSCOPE_H
