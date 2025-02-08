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
    // COPILOT suggestion
    // public:
    //   Device(void) : lgfx::LGFX_Device() {
    //     init();
    //   }
    //   void init(void) {
    //     lgfx::LGFX_Device::begin();
    //     lgfx::LGFX_Device::setRotation(1);
    //     lgfx::LGFX_Device::setBrightness(SCREEN_DEFAULT_BRIGHTNESS);
    //   }
};

#endif // DEVICE_H