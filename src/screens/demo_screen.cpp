#include "screens/demo_screen.h"
#include "components/demo_component.h"
#include <sensors/demo_sensor.h>

/// @brief DemoScreen constructor, generates a scale with a needle line
DemoScreen::DemoScreen(lv_obj_t *base_screen)
{
    DemoComponent *demo_component = new DemoComponent(base_screen);
    DemoSensor *demo_sensor = new DemoSensor(demo_component->_scale);

    demo_component->Init();
}