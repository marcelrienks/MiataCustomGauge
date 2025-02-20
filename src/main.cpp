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
  _demo_screen = new DemoScreen(_device.screen);
  _demo_screen->init();
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

void make_splash_screen(void)
{
  splash_scr = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(splash_scr, lv_color_black(), 0);

  lv_obj_t *icon_three = lv_img_create(splash_scr);
  lv_img_set_src(icon_three, LV_SYMBOL_DUMMY "Clarity"); //&image1_0_resized);
  lv_obj_set_style_text_color(icon_three, lv_color_white(), LV_OPA_0);
  lv_obj_align(icon_three, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_style_img_recolor(icon_three, lv_color_white(), 0);
  lv_obj_set_style_img_recolor_opa(icon_three, LV_OPA_COVER, 0);
}

void setup()
{
  try
  {

    init_logger();

    _device.prepare();

    make_startup_screen();
    make_splash_screen();

    lv_scr_load_anim(splash_scr, LV_SCR_LOAD_ANIM_FADE_IN, 1500, 50, false);

    lv_timer_t *exit_timer = lv_timer_create(fade_out_splash, 2000, NULL); // back to blank
    lv_timer_set_repeat_count(exit_timer, 1);

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
    if (startLooping)
    {
      _demo_screen->update_reading();
    }
    else 
    {
      log("updating screen not started yet");
    }

    // Handle all tasks, to allow screen to render
    Ticker::tick();

    //    // Delay to control the refresh rate (e.g., 30 FPS)
    //    delay(33); // 33 milliseconds delay for approximately 30 FPS
  }
  catch (const std::exception &e)
  {
    log(e.what());
    throw;
  }
}