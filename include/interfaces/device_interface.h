#ifndef DEVICE_INTERFACE_H
#define DEVICE_INTERFACE_H

#include <LovyanGFX.hpp>
#include <lvgl.h>

class IDevice : public lgfx::LGFX_Device
{
public:
    virtual ~IDevice() = default;

    virtual void prepare() = 0;
    virtual void load() = 0;
    virtual void display_flush_callback(lv_display_t *display, const lv_area_t *area, unsigned char *data) = 0;
};

#endif // DEVICE_INTERFACE_H