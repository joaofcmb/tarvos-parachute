#ifndef TARVOS_SENSOR_H
#define TARVOS_SENSOR_H


class sensor {
    virtual bool init() = 0;
    virtual bool stop() = 0;
};


#endif //TARVOS_SENSOR_H
