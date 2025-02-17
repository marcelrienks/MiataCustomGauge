#ifndef OIL_TEMPERATURE_COMPONENT_H
#define OIL_TEMPERATURE_COMPONENT_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_types.h>
#include <sensors/oil_pressure_temperature_sensor.h>

class OilTemperatureComponent
{
private:
    lv_obj_t *_base_screen;
    lv_obj_t *_needle_line;

public:
    OilTemperatureComponent(lv_obj_t *base_screen);
    ~OilTemperatureComponent();

    void init();
    void update_needle(int32_t value);

    lv_obj_t *_scale;
};

#endif // OIL_TEMPERATURE_COMPONENT_H