#define LGFX_USE_V1

#include "main.h"

Device _device;
Preferences _preferences;

// Components
DemoScreen *_demo_screen;

void setup()
{
  try
  {
    Serial.begin(115200);

    _device.prepare();

    _demo_screen = new DemoScreen(_device.screen);
    _demo_screen->init();

    _device.load();

    Ticker::handle_timers();

    Serial.println("Setup finished");
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
    _demo_screen->update_reading();
    Ticker::handle_timers();

    delay(5);
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}