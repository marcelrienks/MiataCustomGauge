#ifndef DEMO_COMPONENT_H
#define DEMO_COMPONENT_H

#include "interfaces/component_interface.h"
#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_types.h>
#include <sensors/demo_sensor.h>

class DemoComponent : IComponent
{
private:
    lv_obj_t *_screen;
    lv_obj_t *_scale;
    lv_obj_t *_needle_line;
    uint32_t _start_time;
    int _current_reading;

    static void set_needle_line_value_callback_wrapper(void *object, int32_t value);

    void animate_needle(int16_t animation_duration, int16_t playback_duration, int32_t start, int32_t end);
    void set_needle_line_value_callback(void *object, int32_t value);

public:
    DemoComponent(lv_obj_t *screen);
    ~DemoComponent();

    void init();
    void update_needle(int32_t value);
};

extern DemoComponent *g_demo_component_instance;

#endif // DEMO_COMPONENT_H