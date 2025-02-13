#include <sensors/demo_sensor.h>
#include <random>

DemoSensor::DemoSensor() {
    
}

int DemoSensor::get_reading() {
    //This is where the sensor would be read, and potentially the data interpreted to some degree

    // Create a random number generator
    std::random_device rd;  // Seed generator
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dis(25, 75); // Define the range

    // Generate a random number in the range [0, 100]
    return dis(gen);
}

DemoSensor::~DemoSensor() {
    
}