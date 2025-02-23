#include "screens/demo_screen.h"
#include "components/demo_component.h"
#include "sensors/demo_sensor.h"
#include "device.h"

/// @brief DemoScreen constructor, generates a component and sensor
DemoScreen::DemoScreen()
{
    _component = new DemoComponent();
    _sensor = new DemoSensor();
}

/// @brief Initialize the screen with component and sensor 
void DemoScreen::init(IDevice *device)
{
    _device = device;

    this->_virtual_screen = lv_obj_create(NULL);
    _component->init(this->_virtual_screen);

    SerialLogger().log_point("DemoScreen::init()", "Completed");
}

/// @brief Show the screen
void DemoScreen::show()
{
    lv_scr_load(this->_virtual_screen);

    SerialLogger().log_point("DemoScreen::show()", "Completed");
}

/// @brief Update the reading on the screen
void DemoScreen::update()
{
    int reading = _sensor->get_reading();
    _component->update(std::make_shared<int>(reading));

    SerialLogger().log_point("DemoScreen::update()", "Completed");
}

/// @brief DemoScreen destructor to clean up dynamically allocated objects
DemoScreen::~DemoScreen()
{
    if (_component)
        delete _component;

    if (_sensor)
        delete _sensor;
}