#include <sensors/oil_pressure_temperature_sensor.h>

OilPressureTemperatureSensor::OilPressureTemperatureSensor()
    : _engine(std::random_device{}()), _pressure_distribution(0, 5), _temperature_distribution(0, 100) // Initialize the generator and distribution
{
    // Seed the engine with a random number from the random device
    // This is a good way to seed the engine, as it is guaranteed to be random
    // This is just an example, and the range could be anything
}

/// @brief Fakes getting a pressure reading from a sensor
/// @return pressure reading
int OilPressureTemperatureSensor::get_pressure_reading()
{
    // This is where the sensor would be read, and potentially the data interpreted to some degree

    // Generate a random number in the range [0, 5]
    return _pressure_distribution(_engine);
}

/// @brief Fakes getting a temperature reading from a sensor
/// @return temperature reading
int OilPressureTemperatureSensor::get_temperature_reading()
{
    // This is where the sensor would be read, and potentially the data interpreted to some degree

    // Generate a random number in the range [0, 100]
    return _temperature_distribution(_engine);
}