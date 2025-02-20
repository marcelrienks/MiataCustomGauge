#ifndef DEMO_SENSOR_H
#define DEMO_SENSOR_H

#include "interfaces/i_sensor.h"
#include "logger/serial_logger.h"

#include <lvgl.h>
#include <LovyanGFX.hpp>
#include <random>

class DemoSensor : ISensor
{
private:
    std::mt19937 _engine;                          // Mersenne Twister engine
    std::uniform_int_distribution<> _distribution; // Uniform distribution

    uint32_t lastReadTime = 0;
    int currentReading = 0;
public:
    DemoSensor();
    int get_reading();
};

#endif // DEMO_SENSOR_H