#include "components/oil_pressure_component.h"

LV_IMAGE_DECLARE(img_hand);
OilPressureComponent *g_oil_pressure_component = nullptr;

/// @brief OilPressureComponent constructor, generates a _scale with a needle line
OilPressureComponent::OilPressureComponent(lv_obj_t *base_screen)
{
    _base_screen = base_screen;
}

/// @brief Initialize the component
void OilPressureComponent::init()
{
    // TODO: does the active screen function work, or must I use the _base_screen
    lv_obj_t *scale_line = lv_scale_create(lv_screen_active());

    lv_obj_set_size(scale_line, 150, 150);
    lv_scale_set_mode(scale_line, LV_SCALE_MODE_ROUND_INNER);
    lv_obj_set_style_bg_opa(scale_line, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(scale_line, lv_palette_lighten(LV_PALETTE_RED, 5), 0);
    lv_obj_set_style_radius(scale_line, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(scale_line, true, 0);
    lv_obj_align(scale_line, LV_ALIGN_LEFT_MID, LV_PCT(2), 0);

    lv_scale_set_label_show(scale_line, true);

    lv_scale_set_total_tick_count(scale_line, 31);
    lv_scale_set_major_tick_every(scale_line, 5);

    lv_obj_set_style_length(scale_line, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale_line, 10, LV_PART_INDICATOR);
    lv_scale_set_range(scale_line, 10, 40);

    lv_scale_set_angle_range(scale_line, 270);
    lv_scale_set_rotation(scale_line, 135);

    _needle_line = lv_line_create(scale_line);

    lv_obj_set_style_line_width(_needle_line, 6, LV_PART_MAIN);
    lv_obj_set_style_line_rounded(_needle_line, true, LV_PART_MAIN);

    lv_anim_t anim_scale_line;
    lv_anim_init(&anim_scale_line);
    lv_anim_set_var(&anim_scale_line, scale_line);
    lv_anim_set_exec_cb(&anim_scale_line, set_needle_line_value_wrapper);
    lv_anim_set_duration(&anim_scale_line, 1000);
    lv_anim_set_repeat_count(&anim_scale_line, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_playback_duration(&anim_scale_line, 1000);
    lv_anim_set_values(&anim_scale_line, 10, 40);
    lv_anim_start(&anim_scale_line);

    lv_obj_t *scale_img = lv_scale_create(lv_screen_active());

    lv_obj_set_size(scale_img, 150, 150);
    lv_scale_set_mode(scale_img, LV_SCALE_MODE_ROUND_INNER);
    lv_obj_set_style_bg_opa(scale_img, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(scale_img, lv_palette_lighten(LV_PALETTE_RED, 5), 0);
    lv_obj_set_style_radius(scale_img, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(scale_img, true, 0);
    lv_obj_align(scale_img, LV_ALIGN_RIGHT_MID, LV_PCT(-2), 0);

    lv_scale_set_label_show(scale_img, true);

    lv_scale_set_total_tick_count(scale_img, 31);
    lv_scale_set_major_tick_every(scale_img, 5);

    lv_obj_set_style_length(scale_img, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale_img, 10, LV_PART_INDICATOR);
    lv_scale_set_range(scale_img, 10, 40);

    lv_scale_set_angle_range(scale_img, 270);
    lv_scale_set_rotation(scale_img, 135);

    /* image must point to the right. E.g. -O------>*/
    _needle_img = lv_image_create(scale_img);
    lv_image_set_src(_needle_img, &img_hand);
    lv_obj_align(_needle_img, LV_ALIGN_CENTER, 47, -2);
    lv_image_set_pivot(_needle_img, 3, 4);

    lv_anim_t anim_scale_img;
    lv_anim_init(&anim_scale_img);
    lv_anim_set_var(&anim_scale_img, scale_img);
    lv_anim_set_exec_cb(&anim_scale_img, OilPressureComponent::set_needle_img_value_wrapper);
    lv_anim_set_duration(&anim_scale_img, 1000);
    lv_anim_set_repeat_count(&anim_scale_img, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_playback_duration(&anim_scale_img, 1000);
    lv_anim_set_values(&anim_scale_img, 10, 40);
    lv_anim_start(&anim_scale_img);
}

void OilPressureComponent::set_needle_line_value_wrapper(void *obj, int32_t v)
{
    g_oil_pressure_component->set_needle_line_value(obj, v);
}

void OilPressureComponent::set_needle_img_value_wrapper(void *obj, int32_t v)
{
    g_oil_pressure_component->set_needle_img_value(obj, v);
}

void OilPressureComponent::set_needle_line_value(void *obj, int32_t v)
{
    lv_scale_set_line_needle_value(static_cast<lv_obj_t *>(obj), _needle_line, 60, v);
}

void OilPressureComponent::set_needle_img_value(void *obj, int32_t v)
{
    lv_scale_set_image_needle_value(static_cast<lv_obj_t *>(obj), _needle_img, v);
}

/// @brief Change the value of the needle line
/// @param value the value to set the needle line to
void OilPressureComponent::update_needle(int32_t value)
{
    lv_scale_set_line_needle_value(_scale, this->_needle_line, 60, value);
    lv_obj_invalidate(_scale);
}

/// @brief DemoComponent destructor to clean up dynamically allocated objects
OilPressureComponent::~OilPressureComponent()
{
    if (_needle_line)
    {
        lv_obj_del(_needle_line);
    }
    if (_scale)
    {
        lv_obj_del(_scale);
    }
}