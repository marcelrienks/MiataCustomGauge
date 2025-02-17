#ifndef OIL_PRESSURE_TEMPERATURE_SENSOR_H
#define OIL_PRESSURE_TEMPERATURE_SENSOR_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_event.h>
#include <random>

class OilPressureTemperatureSensor
{
private:
    std::mt19937 _engine;                                      // Mersenne Twister engine
    std::uniform_int_distribution<> _pressure_distribution;    // Uniform distribution
    std::uniform_int_distribution<> _temperature_distribution; // Uniform distribution

public:
    OilPressureTemperatureSensor();

    int get_pressure_reading();
    int get_temperature_reading();
};

#endif // OIL_PRESSURE_TEMPERATURE_SENSOR_H