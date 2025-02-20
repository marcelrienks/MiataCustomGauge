#ifndef SENSOR_INTERFACE_H
#define SENSOR_INTERFACE_H

class ISensor
{
public:
    virtual ~ISensor() = default;
    virtual int get_reading() = 0;
};

#endif // SENSOR_INTERFACE_H