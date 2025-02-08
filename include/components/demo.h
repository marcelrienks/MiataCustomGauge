#ifndef DEMO_H
#define DEMO_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_event.h>

class Demo
{
private:
  lv_obj_t *_screen;
  lv_obj_t *_needle_line;

public:
  Demo(lv_obj_t *screen);
  ~Demo();

  static void animation_callback_wrapper(void *obj, int32_t v);
  void animation_callback(void *obj, int32_t v);
};

extern Demo *g_demo_instance;

#endif // DEMO_H