#include "utilities/lv_tools.h"

void LvTools::init_blank_screen(lv_obj_t *screen)
{
    screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, lv_color_black(), 0); // Set background color
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, 0);       // Make it fully opaque
}