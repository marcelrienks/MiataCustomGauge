#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "interfaces/i_screen.h"

#include <lvgl.h>

class SplashScreen : IScreen
{
public:
    void init(lv_obj_t *screen);
};

#endif // SPLASH_SCREEN_H