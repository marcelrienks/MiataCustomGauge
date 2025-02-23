#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "interfaces/i_screen.h"
#include "components/clarity_component.h"
#include "utilities/serial_logger.h"
#include "utilities/lv_tools.h"

#include <lvgl.h>

#define ANIMATION_TIME 1000
#define DELAY_TIME 0
#define DISPLAY_TIME 500

static void transition_timer_callback(lv_timer_t *timer);

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
    void fade_in_splash_screen();
    void fade_out_splash_screen();
    void update();
};

#endif // SPLASH_SCREEN_H