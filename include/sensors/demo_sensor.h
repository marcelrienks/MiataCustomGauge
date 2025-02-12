#ifndef DEMO_SENSOR_H
#define DEMO_SENSOR_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_event.h>

class DemoSensor
{
public:
    lv_obj_t *_needle_line;

    DemoSensor();
    ~DemoSensor();
};

#endif // DEMO_SENSOR_H