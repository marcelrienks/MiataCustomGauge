#ifndef DEMO_SCREEN_H
#define DEMO_SCREEN_H

#include "interfaces/i_screen.h"
#include "components/demo_component.h"
#include "sensors/demo_sensor.h"
#include "logger/serial_logger.h"

#include <lvgl.h>

class DemoScreen : IScreen
{
public:
    DemoComponent *_demo_component;
    DemoSensor *_demo_sensor;

    DemoScreen();
    ~DemoScreen();

    void init(lv_obj_t *screen);
    void update();
};

#endif // DEMO_SCREEN_H