#ifndef MAIN_H
#define MAIN_H

#define UI_VERSION "4.1.0"

#include "Arduino.h"
#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <Preferences.h>
#include "logger/serial_logger.h"
#include "screens/demo_screen.h"
#include "device.h"
#include "ticker.h"

Device _device;
Preferences _preferences;

// Components
DemoScreen *_demo_screen;

#endif