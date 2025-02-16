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
    lv_anim_exec_xcb_t animation_cb;
    lv_anim_t anim_scale_line;
    int currentValue;
    uint32_t startTime;

public:
    DemoComponent(lv_obj_t *base_screen);
    ~DemoComponent();

    void init();
    void update_needle(int32_t value);
    void register_animation_cb(lv_anim_exec_xcb_t cb);
    void set_inst_needle_line_value(void * obj, int32_t v);

    lv_obj_t *_scale;
};

#endif // DEMO_COMPONENT_H