#ifndef I_SCREEN_H
#define I_SCREEN_H

#include "interfaces/i_device.h"
#include "interfaces/i_component.h"
#include "interfaces/i_sensor.h"

#include <lvgl.h>

class IScreen
{
private:
    IDevice *_device;
    lv_obj_t *_virtual_screen;

public:
    virtual void init(IDevice *device) = 0;
    virtual void show() = 0;
    virtual void update() = 0;
};

#endif // I_SCREEN_H
