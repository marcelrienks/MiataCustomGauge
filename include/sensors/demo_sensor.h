#ifndef DEMO_SENSOR_H
#define DEMO_SENSOR_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_event.h>
#include <random>

class DemoSensor
{
private:
    std::mt19937 _engine;                         // Mersenne Twister engine
    std::uniform_int_distribution<> _distribution; // Uniform distribution

public:
    DemoSensor();
    ~DemoSensor();

    int get_reading();
};

#endif // DEMO_SENSOR_H