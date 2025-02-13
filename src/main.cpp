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

    // Create and initialise the demo screen by passing device as a dependency
    _demo_screen = new DemoScreen(_device.screen);
    _demo_screen->init();

    // Load all screens associated with device
    _device.load();

    // Handle all tasks, to allow screen to render
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
    // Update the reading on the screen
    _demo_screen->update_reading();

    // Handle all tasks, to allow screen to render
    Ticker::handle_timers();

    delay(100);
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}