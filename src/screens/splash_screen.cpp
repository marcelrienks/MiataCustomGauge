#include "screens/splash_screen.h"
#include "utilities/lv_tools.h"

/// @brief SplashScreen constructor, generates a component and sensor
SplashScreen::SplashScreen()
{
    _component = new ClarityComponent();
}

/// @brief Initialize the screen with component and sensor 
void SplashScreen::init(IDevice *device)
{
    _device = device;

    this->_virtual_screen = lv_obj_create(NULL);
    _component->init(this->_virtual_screen);
}

/// @brief Show the screen
void SplashScreen::show()
{
    // Fade in the clarity splash screen
    lv_scr_load_anim(_virtual_screen, LV_SCR_LOAD_ANIM_FADE_IN, 1000, 0, true);

    // Fade back to black
    lv_obj_t *blank_screen;
    LvTools::init_blank_screen(blank_screen);
    lv_scr_load_anim(blank_screen, LV_SCR_LOAD_ANIM_FADE_OUT, 1000, 500, true);
}

/// @brief Update the reading on the screen
void SplashScreen::update()
{
    // Not needed but required to satisfy interface
}

/// @brief SplashScreen destructor to clean up dynamically allocated objects
SplashScreen::~SplashScreen()
{
    if (_component)
        delete _component;
}