#ifndef SPLASH_COMPONENT_H
#define SPLASH_COMPONENT_H

#include "interfaces/component_interface.h"

class ClarityComponent : IComponent
{
private:
    lv_obj_t *_screen;

public:
    ClarityComponent(lv_obj_t *screen);
    ~ClarityComponent();

    void init();
};

#endif // SPLASH_COMPONENT_H