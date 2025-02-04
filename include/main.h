#ifndef MAIN_H
#define MAIN_H

#define UI_VERSION "4.1.0"

#include "Arduino.h"
#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <string.h>
#include <Preferences.h>
#include "meter.h"

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

#define MAX_FILE_OPEN 10

#endif