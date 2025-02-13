#include <sensors/demo_sensor.h>

DemoSensor::DemoSensor()
    : _engine(std::random_device{}()), _distribution(25, 75) // Initialize the generator and distribution
{
    // Seed the engine with a random number from the random device
    // This is a good way to seed the engine, as it is guaranteed to be random
    // The distribution is set to be between 25 and 75, as this is a common range for temperature sensors
    // This is just an example, and the range could be anything
}

int DemoSensor::get_reading()
{
    // This is where the sensor would be read, and potentially the data interpreted to some degree

    // Generate a random number in the range [0, 100]
    return _distribution(_engine);
}

DemoSensor::~DemoSensor()
{
}