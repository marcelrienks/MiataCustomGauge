#include "logger/serial_logger.h"

void init_logger() 
{
  #ifdef CLARITY_DEBUG
    Serial.begin(115200);
  #endif
}

void log(const String &logMessage)
{
  #ifdef CLARITY_DEBUG
  Serial.println(logMessage);
  #endif  
}