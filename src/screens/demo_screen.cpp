#include "screens/demo_screen.h"
#include "components/demo_component.h"
#include "sensors/demo_sensor.h"

/// @brief DemoScreen constructor, generates a component and sensor
DemoScreen::DemoScreen()
{
    _demo_component = new DemoComponent();
    _demo_sensor = new DemoSensor();
}

/// @brief Initialize the screen with component and sensor 
void DemoScreen::init(lv_obj_t *screen)
{
    _demo_component->init(screen);
}

/// @brief Update the reading on the screen
void DemoScreen::update()
{
    int reading = _demo_sensor->get_reading();
    _demo_component->update(reading);
}

/// @brief DemoScreen destructor to clean up dynamically allocated objects
DemoScreen::~DemoScreen()
{
    if (_demo_component)
        delete _demo_component;

    if (_demo_sensor)
        delete _demo_sensor;
}