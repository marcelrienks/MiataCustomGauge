#ifndef DEMO_SENSOR_H
#define DEMO_SENSOR_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_event.h>

class DemoSensor
{
public:
    DemoSensor();
    ~DemoSensor();

    int get_reading();
};

#endif // DEMO_SENSOR_H