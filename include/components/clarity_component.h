#ifndef CLARITY_COMPONENT_H
#define CLARITY_COMPONENT_H

#include "interfaces/i_component.h"

class ClarityComponent : IComponent
{
public:
    void init(lv_obj_t *screen);
};

#endif // CLARITY_COMPONENT_H