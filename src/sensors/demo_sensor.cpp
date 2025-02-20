#include "sensors/demo_sensor.h"

DemoSensor::DemoSensor()
{
    _engine = std::mt19937(std::random_device{}());
    _distribution = std::uniform_int_distribution<int>(0, 100);
}

/// @brief Fakes getting a temperature reading from a sensor
/// @return temperature reading
int DemoSensor::get_reading()
{
    uint32_t elapsedTime = millis() - this->lastReadTime;

    // This is where the sensor would be read, and potentially the data interpreted to some degree
    if (this->lastReadTime == 0 || elapsedTime > 1000) //TODO: convert this into the global variable mentioned on Main
    {
        this->lastReadTime = millis();

        // Generate a random number in the range [0, 100]
        this->currentReading = _distribution(_engine);

        log_value("DemoSensor::get_reading()", "currentReading", String(this->currentReading));//TODO: the currentReading value is not being shown in the logs
    }
    
    return this->currentReading;
}