#ifndef MAIN_H
#define MAIN_H

#define UI_VERSION "4.1.0"

#include "logger/serial_logger.h"
#include "screens/demo_screen.h"
#include "device.h"
#include "ticker.h"

#include <Arduino.h>
#include <lvgl.h>
#include <LovyanGFX.hpp>
#include <Preferences.h>

Device _device;
Preferences _preferences;

// Components
DemoScreen *_demo_screen;

#endif