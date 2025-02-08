#define LGFX_USE_V1

#include "main.h"

Device _device;
Preferences _preferences;

// Components
Demo *_demo;

void setup()
{
  try
  {
    Serial.begin(115200);

    _device.prepare();

    _demo = new Demo(_device.screen);

    _device.load();

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
    Ticker::handle_timers();
    delay(5);
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}