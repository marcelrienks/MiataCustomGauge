#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "interfaces/i_screen.h"
#include "components/clarity_component.h"

#include <lvgl.h>

class SplashScreen : public IScreen
{
private:
    IDevice *_device;
    lv_obj_t *_virtual_screen;
    ClarityComponent *_component;

public:
    SplashScreen();
    ~SplashScreen();

    void init(IDevice *device);
    void show();
    void update();
};

#endif // SPLASH_SCREEN_H