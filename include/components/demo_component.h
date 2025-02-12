#ifndef DEMO_COMPONENT_H
#define DEMO_COMPONENT_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_types.h>
#include <sensors/demo_sensor.h>

class DemoComponent
{
private:
    lv_obj_t *_base_screen;

public:
    DemoComponent(lv_obj_t *base_screen, DemoSensor *demo_sensor);
    ~DemoComponent();
};

#endif // DEMO_COMPONENT_H