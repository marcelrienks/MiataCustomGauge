#ifndef DEVICE_H
#define DEVICE_H

#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <lvgl.h>

// Screen
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 240
#define SCREEN_OFFSET_X 0
#define SCREEN_OFFSET_Y 0
#define SCREEN_RGB_ORDER false
#define SCREEN_DEFAULT_BRIGHTNESS 100

// Display
#define SPI SPI2_HOST

// Pins
#define SCLK 18
#define MOSI 23
#define MISO -1
#define DC 16
#define CS 22
#define RST 4
#define BL 3
#define BUZZER -1

class Device : public lgfx::LGFX_Device
{
private:
    lgfx::Panel_GC9A01 _panel_instance;
    lgfx::Light_PWM _light_instance;
    lgfx::Bus_SPI _bus_instance;

public:
    Device();
    ~Device();

    void Init();
};

#endif // DEVICE_H