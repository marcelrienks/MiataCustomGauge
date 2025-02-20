#ifndef DEMO_SCREEN_H
#define DEMO_SCREEN_H

#include "components/demo_component.h"
#include "sensors/demo_sensor.h"
#include "logger/serial_logger.h"

class DemoScreen
{
public:
    DemoComponent *_demo_component;
    DemoSensor *_demo_sensor;

    DemoScreen(lv_obj_t *screen);
    ~DemoScreen();

    void init();
    void update_reading();
};

#endif // DEMO_SCREEN_H