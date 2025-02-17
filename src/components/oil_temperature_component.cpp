#include "components/oil_temperature_component.h"

/// @brief OilTemperatureComponent constructor, generates a _scale with a needle line
OilTemperatureComponent::OilTemperatureComponent(lv_obj_t *base_screen)
{
    _base_screen = base_screen;
}

/// @brief Initialize the component
void OilTemperatureComponent::init()
{

}

/// @brief Change the value of the needle line
/// @param value the value to set the needle line to
void OilTemperatureComponent::update_needle(int32_t value)
{
    lv_scale_set_line_needle_value(_scale, this->_needle_line, 60, value);
    lv_obj_invalidate(_scale);
}

/// @brief DemoComponent destructor to clean up dynamically allocated objects
OilTemperatureComponent::~OilTemperatureComponent()
{
    if (_needle_line) {
        lv_obj_del(_needle_line);
    }
    if (_scale) {
        lv_obj_del(_scale);
    }
}