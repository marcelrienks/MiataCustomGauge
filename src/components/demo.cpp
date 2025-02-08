#include "components/demo.h"

Demo *g_demo_instance = nullptr;

// TODO: extend the component event model
Demo::Demo(lv_obj_t *screen)
{
  g_demo_instance = this;
  this->_screen = screen;

  // /*Create an Arc*/
  // static lv_style_t style;
  // lv_style_init(&style);

  // lv_style_set_arc_color(&style, lv_palette_main(LV_PALETTE_RED));
  // lv_style_set_arc_width(&style, 4);

  // lv_obj_t * arc = lv_arc_create(this->display);
  // lv_obj_add_style(arc, &style, 0);

  // lv_obj_set_size(arc, 150, 150);
  // lv_arc_set_rotation(arc, 135);
  // lv_arc_set_bg_angles(arc, 0, 270);
  // lv_arc_set_value(arc, 50);
  // lv_obj_center(arc);
  //  lv_obj_add_event_cb(arc, value_changed_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

  // /*Manually update the label for the first time*/
  // lv_obj_send_event(arc, LV_EVENT_VALUE_CHANGED, NULL);
  lv_obj_t *scale = lv_scale_create(this->_screen);
  lv_obj_set_size(scale, 150, 150);
  lv_scale_set_label_show(scale, true);
  lv_scale_set_mode(scale, LV_SCALE_MODE_ROUND_OUTER);
  lv_obj_center(scale);

  lv_scale_set_total_tick_count(scale, 21);
  lv_scale_set_major_tick_every(scale, 5);

  lv_obj_set_style_length(scale, 5, LV_PART_ITEMS);
  lv_obj_set_style_length(scale, 10, LV_PART_INDICATOR);
  lv_scale_set_range(scale, 0, 100);

  static const char *custom_labels[] = {"0 °C", "25 °C", "50 °C", "75 °C", "100 °C", NULL};
  lv_scale_set_text_src(scale, custom_labels);

  static lv_style_t indicator_style;
  lv_style_init(&indicator_style);

  /* Label style properties */
  lv_style_set_text_font(&indicator_style, LV_FONT_DEFAULT);
  lv_style_set_text_color(&indicator_style, lv_palette_darken(LV_PALETTE_BLUE, 3));

  /* Major tick properties */
  lv_style_set_line_color(&indicator_style, lv_palette_darken(LV_PALETTE_BLUE, 3));
  lv_style_set_width(&indicator_style, 10U);     /*Tick length*/
  lv_style_set_line_width(&indicator_style, 2U); /*Tick width*/
  lv_obj_add_style(scale, &indicator_style, LV_PART_INDICATOR);

  static lv_style_t minor_ticks_style;
  lv_style_init(&minor_ticks_style);
  lv_style_set_line_color(&minor_ticks_style, lv_palette_lighten(LV_PALETTE_BLUE, 2));
  lv_style_set_width(&minor_ticks_style, 5U);      /*Tick length*/
  lv_style_set_line_width(&minor_ticks_style, 2U); /*Tick width*/
  lv_obj_add_style(scale, &minor_ticks_style, LV_PART_ITEMS);

  static lv_style_t main_line_style;
  lv_style_init(&main_line_style);
  /* Main line properties */
  lv_style_set_arc_color(&main_line_style, lv_palette_darken(LV_PALETTE_BLUE, 3));
  lv_style_set_arc_width(&main_line_style, 2U); /*Tick width*/
  lv_obj_add_style(scale, &main_line_style, LV_PART_MAIN);

  /* Add a section */
  static lv_style_t section_minor_tick_style;
  static lv_style_t section_label_style;
  static lv_style_t section_main_line_style;

  lv_style_init(&section_label_style);
  lv_style_init(&section_minor_tick_style);
  lv_style_init(&section_main_line_style);

  /* Label style properties */
  lv_style_set_text_font(&section_label_style, LV_FONT_DEFAULT);
  lv_style_set_text_color(&section_label_style, lv_palette_darken(LV_PALETTE_RED, 3));

  lv_style_set_line_color(&section_label_style, lv_palette_darken(LV_PALETTE_RED, 3));
  lv_style_set_line_width(&section_label_style, 5U); /*Tick width*/

  lv_style_set_line_color(&section_minor_tick_style, lv_palette_lighten(LV_PALETTE_RED, 2));
  lv_style_set_line_width(&section_minor_tick_style, 4U); /*Tick width*/

  /* Main line properties */
  lv_style_set_arc_color(&section_main_line_style, lv_palette_darken(LV_PALETTE_RED, 3));
  lv_style_set_arc_width(&section_main_line_style, 4U); /*Tick width*/

  /* Configure section styles */
  lv_scale_section_t *section = lv_scale_add_section(scale);
  lv_scale_section_set_range(section, 75, 100);
  lv_scale_section_set_style(section, LV_PART_INDICATOR, &section_label_style);
  lv_scale_section_set_style(section, LV_PART_ITEMS, &section_minor_tick_style);
  lv_scale_section_set_style(section, LV_PART_MAIN, &section_main_line_style);

  this->_needle_line = lv_line_create(scale);
  lv_obj_set_style_line_color(this->_needle_line, lv_palette_lighten(LV_PALETTE_INDIGO, 3), 0);
  lv_obj_set_style_line_width(this->_needle_line, 6, LV_PART_MAIN);
  lv_obj_set_style_line_rounded(this->_needle_line, true, LV_PART_MAIN);
  lv_scale_set_line_needle_value(scale, this->_needle_line, 60, 0);

  lv_anim_t anim_scale_line;
  lv_anim_init(&anim_scale_line);
  lv_anim_set_var(&anim_scale_line, scale);
  lv_anim_set_exec_cb(&anim_scale_line, Demo::animation_callback_wrapper);
  lv_anim_set_duration(&anim_scale_line, 1000);
  lv_anim_set_repeat_count(&anim_scale_line, LV_ANIM_REPEAT_INFINITE);
  lv_anim_set_playback_duration(&anim_scale_line, 1000);
  lv_anim_set_values(&anim_scale_line, 25, 75);
  lv_anim_start(&anim_scale_line);
}

void Demo::animation_callback_wrapper(void *obj, int32_t v)
{
  if (g_demo_instance != nullptr)
    g_demo_instance->animation_callback(obj, v);
}

void Demo::animation_callback(void *scale, int32_t value)
{
  lv_scale_set_line_needle_value((lv_obj_t *)scale, g_demo_instance->_needle_line, 60, value);
}

Demo::~Demo()
{
  if (g_demo_instance == this)
    g_demo_instance = nullptr;
}

// static void value_changed_event_cb(lv_event_t * e)
// {
//     lv_obj_t * arc = lv_event_get_target_obj(e);
//     lv_obj_t * label = (lv_obj_t *)lv_event_get_user_data(e);
//     lv_label_set_text_fmt(label, "%" LV_PRId32 "%%", lv_arc_get_value(arc));
//     /*Rotate the label to the current position of the arc*/
//     lv_arc_rotate_obj_to_angle(arc, label, 25);
// }
