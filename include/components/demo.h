#ifndef DEMO_H
#define DEMO_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_event.h>

class Demo
{
public:
  Demo(lv_obj_t *screen);
  static void animation_callback_wrapper(lv_anim_exec_xcb_t cb);
  void animation_callback(void *obj, int32_t v);

private:
  lv_obj_t *_screen;
  lv_obj_t *_needle_line;
  lv_anim_exec_xcb_t _animation_callback;
};

extern Demo *g_demo_instance;

#endif // DEMO_H