#include <sensors/demo_sensor.h>

DemoSensor::DemoSensor() {
    _needle_line = lv_line_create(scale);
    lv_obj_set_style_line_color(_needle_line, lv_palette_lighten(LV_PALETTE_INDIGO, 3), 0);
    lv_obj_set_style_line_width(_needle_line, 6, LV_PART_MAIN);
    lv_obj_set_style_line_rounded(_needle_line, true, LV_PART_MAIN);
    lv_scale_set_line_needle_value(scale, _needle_line, 60, 0);
}