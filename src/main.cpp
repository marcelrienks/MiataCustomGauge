#define LGFX_USE_V1

#include "main.h"

Device device;
Preferences preferences;

// Components
Demo *demo;

void setup()
{
  try
  {
    Serial.begin(115200);

    device.Init();

    // create Demo
    demo = new Demo(device.screen);

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