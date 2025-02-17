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
    lv_obj_t *_base_screen;
    lv_obj_t *_scale;
    lv_obj_t *_needle_line;
    lv_anim_t *_anim_scale_line;
    int _current_value;
    uint32_t _start_time;

public:
    DemoComponent(lv_obj_t *base_screen);
    ~DemoComponent();

    void init();
    void update_needle(int32_t value);
    void animate_needle(int16_t animation_duration, int16_t playback_duration, int32_t start, int32_t end);

    static void set_needle_line_value_callback_wrapper(void *object, int32_t value);
    void set_needle_line_value_callback(void *object, int32_t value);
};

extern DemoComponent *g_demo_component_instance;

#endif // DEMO_COMPONENT_H