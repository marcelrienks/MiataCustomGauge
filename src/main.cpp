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
    Ticker::HandleTimers();

    delay(5);
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}