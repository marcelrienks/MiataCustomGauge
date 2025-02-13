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
    lv_obj_t *_needle_line;

public:
    DemoComponent(lv_obj_t *base_screen);
    ~DemoComponent();

    void init();
    void update_needle(int32_t value);

    lv_obj_t *_scale;
};

#endif // DEMO_COMPONENT_H