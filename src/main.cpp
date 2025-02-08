#define LGFX_USE_V1

#include "main.h"

Device device;
Preferences preferences;

// TODO: convert this to a class object, with lv_obj_t and custom screen functions below
//  Screens
lv_obj_t *screen;

// Components
Meter *meter;

void set_needle_line_value(void *obj, int32_t v)
{
  meter->set_needle_line_value(obj, v);
}

void setup()
{
  try
  {
    Serial.begin(115200);

    device.Init();

    screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, LV_PART_MAIN);

    // init Meter
    meter = new Meter(screen);
    meter->register_animation_cb(set_needle_line_value);
    meter->build();

    lv_scr_load(screen);

    Serial.print("Setup finished");
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}

void loop()
{
  try
  {
    // TODO: refactor this to use a global variable and an external function call
    static uint32_t lastTick = millis();
    uint32_t current = millis();
    lv_tick_inc(current - lastTick);
    lastTick = current;
    lv_timer_handler();

    delay(5);
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}