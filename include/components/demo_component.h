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
    DemoComponent(lv_obj_t *base_screen);
    ~DemoComponent();

    void Init();

    static void animation_callback_wrapper(void *scale, int32_t needle_value);
    void animation_callback(void *scale, int32_t needle_value);

    lv_obj_t *_scale;
};

extern DemoComponent *g_demo_component_instance;

#endif // DEMO_COMPONENT_H