#ifndef DEMO_H
#define DEMO_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_event.h>

class Demo
{
public:
  Demo(lv_obj_t *screen);
  static void AnimationCallbackWrapper(lv_anim_exec_xcb_t cb);
  void AnimationCallback(void *obj, int32_t v);

private:
  lv_obj_t *screen;
  lv_obj_t *needle_line;
  lv_anim_exec_xcb_t animation_cb;
};

extern Demo *g_demo_instance;

#endif // DEMO_H