#include "screens/demo_screen.h"
#include "components/demo_component.h"
#include "sensors/demo_sensor.h"

/// @brief DemoScreen constructor, generates a component and sensor
DemoScreen::DemoScreen(lv_obj_t *base_screen)
{
    _demo_component = new DemoComponent(base_screen);
    _demo_sensor = new DemoSensor();
}

/// @brief Initialize the screen with component and sensor 
void DemoScreen::init()
{
    _demo_component->init();
}

void DemoScreen::update_reading()
{
    int reading = _demo_sensor->get_reading();
    Serial.print("reading = ");
    Serial.print(reading);
    Serial.println();
    _demo_component->update_needle(reading);
}

DemoScreen::~DemoScreen()
{
}