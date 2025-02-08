#define LGFX_USE_V1

#include "main.h"

Device device;
Preferences preferences;

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
    
    // init Meter
    meter = new Meter(device.screen);
    meter->register_animation_cb(set_needle_line_value);
    meter->build();

    device.Load();

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