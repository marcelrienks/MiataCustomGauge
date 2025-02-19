#ifndef COMPONENT_INTERFACE_H
#define COMPONENT_INTERFACE_H

#include <lvgl.h>

class IComponent
{
public:
    virtual ~IComponent() = default;

    virtual void init() = 0;
    virtual void update(int32_t value) = 0;
};

#endif // COMPONENT_INTERFACE_H