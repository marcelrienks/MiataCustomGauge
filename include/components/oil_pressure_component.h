#ifndef OIL_PRESSURE_COMPONENT_H
#define OIL_PRESSURE_COMPONENT_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_types.h>
#include <sensors/oil_pressure_temperature_sensor.h>

class OilPressureComponent
{
private:
    lv_obj_t *_base_screen;
    lv_obj_t *_needle_line;
    lv_obj_t *_needle_img;

public:
    OilPressureComponent(lv_obj_t *base_screen);
    ~OilPressureComponent();

    void init();

    static void set_needle_line_value_wrapper(void *obj, int32_t v);
    static void set_needle_img_value_wrapper(void *obj, int32_t v);

    void set_needle_line_value(void *obj, int32_t v);
    void set_needle_img_value(void *obj, int32_t v);

    void update_needle(int32_t value);

    lv_obj_t *_scale;
};

extern OilPressureComponent *g_oil_pressure_component;

#endif // OIL_PRESSURE_COMPONENT_H