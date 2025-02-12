#include "screens/demo_screen.h"
#include "components/demo_component.h"
#include <sensors/demo_sensor.h>

/// @brief DemoScreen constructor, generates a scale with a needle line
DemoScreen::DemoScreen(lv_obj_t *base_screen)
{
    DemoSensor *demo_sensor = new DemoSensor();
    DemoComponent *demo_component = new DemoComponent(base_screen, demo_sensor);
}