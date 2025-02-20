#ifndef I_SCREEN_H
#define I_SCREEN_H

#include <lvgl.h>

class IScreen
{
public:
    virtual void init(lv_obj_t *screen) = 0;
    virtual void update() = 0;
};

#endif // I_SCREEN_H
