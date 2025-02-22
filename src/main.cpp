#define LGFX_USE_V1

#include "main.h"

// TODO: create a screen level duration variable to control the duration of the animation / or delays if that screen does not animate
// TODO: create an interface for screen & component, with generics, so that swapping them in and out is standardised
// TODO: create a screen manager to handle the screen transitions
// TODO: refactor startup screen function to use screen manager
// TODO: see if any refactoring of splash screen is needed

void setup()
{
  try
  {
    _device.prepare();

    auto *splash_screen = new SplashScreen();
    splash_screen->init(&_device);
    splash_screen->show();

    auto *demo_screen = new DemoScreen();
    demo_screen->init(&_device);
    demo_screen->show();

    // Handle all tasks, to allow screen to render
    Ticker::tick();

    SerialLogger().log_point("main::setup()", "completed");
  }
  catch (const std::exception &e)
  {
    SerialLogger().log_message(e.what());
    throw;
  }
  catch (...)
  {
    SerialLogger().log_point("main::setup()", "Unknown exception occurred");
    throw;
  }
}

void loop()
{
  try
  {
    _demo_screen->update();

    // Handle all tasks, to allow screen to render
    Ticker::tick();
  }
  catch (const std::exception &e)
  {
    SerialLogger().log_message(e.what());
    throw;
  }
  catch (...)
  {
    SerialLogger().log_point("main::loop()", "Unknown exception occurred");
    throw;
  }
}