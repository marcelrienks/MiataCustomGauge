#ifndef SERIAL_LOGGER_H
#define SERIAL_LOGGER_H

#include "Arduino.h"

void init_logger();
void log(const String &logMessage);

#endif