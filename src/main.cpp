#define LGFX_USE_V1

#include "main.h"

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
    Ticker::tick();
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
    Ticker::tick();

//    // Delay to control the refresh rate (e.g., 30 FPS)
//    delay(33); // 33 milliseconds delay for approximately 30 FPS
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}