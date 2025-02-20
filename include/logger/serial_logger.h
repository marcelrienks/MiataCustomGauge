#ifndef SERIAL_LOGGER_H
#define SERIAL_LOGGER_H

#include "Arduino.h"

void init_logger();
void log_message(const String &logMessage);
void log_point(const String &point, const String &message);
void log_value(const String &point, const String &variable_name, const String &value);
void log_exception(const String &point, const String &exception);

#endif