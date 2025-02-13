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
    _demo_screen->update_reading();
    delay(1000);

    Serial.print("loop finished");
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}