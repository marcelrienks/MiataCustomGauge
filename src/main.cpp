#define LGFX_USE_V1

#include "main.h"

lv_obj_t *startup_scr; // Black startup screen
lv_obj_t *splash_scr;  // Splash screen
bool startLooping = false;

// TODO: create a screen level duration variable to control the duration of the animation / or delays if that screen does not animate
// TODO: create an interface for screen & component, with generics, so that swapping them in and out is standardised
// TODO: create a screen manager to handle the screen transitions
// TODO: refactor startup screen function to use screen manager
// TODO: see if any refactoring of splash screen is needed

void fade_in_home(lv_timer_t *timer)
{
  // Create and initialise the demo screen by passing device as a dependency
  _demo_screen = new DemoScreen();
  _demo_screen->init(_device.screen);
  // Load all screens associated with device
  _device.load();
  // allow reading from sensors
  startLooping = true;
  lv_obj_delete(splash_scr);
}

void fade_out_splash(lv_timer_t *timer)
{
  lv_scr_load_anim(startup_scr, LV_SCR_LOAD_ANIM_FADE_IN, 1000, 0, false);

  lv_timer_t *exit_timer = lv_timer_create(fade_in_home, 2000, NULL); // back to blank
  lv_timer_set_repeat_count(exit_timer, 1);
}

void make_startup_screen()
{
  startup_scr = lv_screen_active(); // Make startup screen active
  lv_obj_set_style_bg_color(startup_scr, lv_color_black(), LV_PART_MAIN);
  lv_obj_set_style_bg_opa(startup_scr, LV_OPA_COVER, LV_PART_MAIN);
}

void setup()
{
  try
  {
    _device.prepare();

    //TODO: create splash screen
    //TODO: create home screen

    //TODO: fade splash screen in and out
    //TODO: show home screen

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
    // Update the reading on the screen
    if (startLooping)
      _demo_screen->update();

    else
      SerialLogger().log_message("Updating screen not started yet");

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