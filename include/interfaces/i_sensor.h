#ifndef I_SENSOR_H
#define I_SENSOR_H

class ISensor
{
public:
    virtual int get_reading() = 0;
};

#endif // I_SENSOR_H