#ifndef DEMO_SENSOR_H
#define DEMO_SENSOR_H

#include "interfaces/sensor_interface.h"
#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_event.h>
#include <random>
#include "logger/serial_logger.h"

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