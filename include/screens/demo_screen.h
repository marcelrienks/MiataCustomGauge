#ifndef DEMO_SCREEN_H
#define DEMO_SCREEN_H

#include "interfaces/i_screen.h"
#include "components/demo_component.h"
#include "sensors/demo_sensor.h"
#include "utilities/serial_logger.h"

#include <lvgl.h>

class DemoScreen : public IScreen
{
private:
    IDevice *_device;
    lv_obj_t *_virtual_screen;
    DemoComponent *_component;
    DemoSensor *_sensor;

public:
    DemoScreen();
    ~DemoScreen();

    void init(IDevice *device);
    void show();
    void update();
};

#endif // DEMO_SCREEN_H