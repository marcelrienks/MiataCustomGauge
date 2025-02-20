#ifndef I_COMPONENT_H
#define I_COMPONENT_H

#include <lvgl.h>

class IComponent
{
public:
    virtual void init(lv_obj_t *screen) = 0;
    virtual void update(int32_t value) = 0;
};

#endif // I_COMPONENT_H