#define LGFX_USE_V1
#include "Arduino.h"
#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <string.h>
#include <Preferences.h>
#include "main.h"

class LGFX : public lgfx::LGFX_Device
{
  lgfx::Panel_GC9A01 _panel_instance;
  lgfx::Light_PWM _light_instance;
  lgfx::Bus_SPI _bus_instance;

public:
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config();
      cfg.spi_host = SPI;
      cfg.spi_mode = 0;
      cfg.freq_write = 80000000;
      cfg.freq_read = 20000000;
      cfg.spi_3wire = true;
      cfg.use_lock = true;
      cfg.dma_channel = SPI_DMA_CH_AUTO;
      cfg.pin_sclk = SCLK;
      cfg.pin_mosi = MOSI;
      cfg.pin_miso = MISO;
      cfg.pin_dc = DC;

      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    {
      auto cfg = _panel_instance.config();

      cfg.pin_cs = CS;
      cfg.pin_rst = RST;
      cfg.pin_busy = -1;

      cfg.memory_width = WIDTH;
      cfg.memory_height = HEIGHT;
      cfg.panel_width = WIDTH;
      cfg.panel_height = HEIGHT;
      cfg.offset_x = OFFSET_X;
      cfg.offset_y = OFFSET_Y;
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = false;
      cfg.invert = true;
      cfg.rgb_order = RGB_ORDER;
      cfg.dlen_16bit = false;
      cfg.bus_shared = false;

      _panel_instance.config(cfg);
    }

    {
      auto cfg = _light_instance.config();

      cfg.pin_bl = BL;
      cfg.invert = false;
      cfg.freq = 44100;
      cfg.pwm_channel = 1;

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);
    }

    setPanel(&_panel_instance);
  }
};
LGFX tft;
Preferences prefs;

static const uint32_t screenWidth = WIDTH;
static const uint32_t screenHeight = HEIGHT;
lv_color_t black = lv_color_make(0, 0, 0);

const unsigned int lvBufferSize = screenWidth * 10;
uint8_t lvBuffer[2][lvBufferSize];

// Screen Dimming
const uint8_t DIM_BRIGHTNESS = 10;
const uint8_t DEFAULT_BRIGHTNESS = 100;
bool isScreenDimmed = false;

void screenBrightness(uint8_t value)
{
  tft.setBrightness(value);
}
void checkScreenDimming()
{
  // TODO: wire up the 'false' to a check if screen should be dimmed
  if (!isScreenDimmed && false)
  {
    // Time to dim the screen
    screenBrightness(DIM_BRIGHTNESS);
    isScreenDimmed = true;
  }
}
void resetScreenBrightness()
{
  if (isScreenDimmed)
  {
    screenBrightness(DEFAULT_BRIGHTNESS);
    isScreenDimmed = false;
  }
}

// TODO: is this required?
void my_disp_flush(lv_display_t *display, const lv_area_t *area, unsigned char *data)
{
  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);
  lv_draw_sw_rgb565_swap(data, w * h);

  if (tft.getStartCount() == 0)
  {
    tft.endWrite();
  }

  tft.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (uint16_t *)data);
  lv_disp_flush_ready(display);
}

// Screens
lv_obj_t *home_screen;

// Objects
lv_obj_t *arc;

// Elements for Home Screen
void make_arc()
{
  lv_color_t stored_color = lv_color_make(140, 0, 255);

  // Create the arc
  arc = lv_arc_create(home_screen);
  lv_obj_set_size(arc, 200, 200);
  lv_obj_set_style_arc_width(arc, 20, LV_PART_INDICATOR);
  lv_obj_set_style_arc_width(arc, 20, LV_PART_MAIN);
  lv_arc_set_bg_angles(arc, 120, 60);
  lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
  lv_obj_set_style_arc_color(arc, lv_color_make(60, 60, 60), LV_PART_MAIN);
  lv_obj_set_style_arc_color(arc, lv_color_make(60, 60, 60), LV_PART_INDICATOR);
  lv_arc_set_range(arc, 0, 100);
  lv_arc_set_value(arc, 100);
  lv_obj_align(arc, LV_ALIGN_CENTER, 0, 0);
}

// Make Home Screen
void make_home_screen()
{
  home_screen = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(home_screen, black, LV_PART_MAIN);
  lv_obj_set_style_bg_opa(home_screen, LV_OPA_COVER, LV_PART_MAIN);

  make_arc();
}

void setup()
{
  try
  {
    Serial.begin(115200);

    int rt = prefs.getInt("rotate", 0);
    int br = prefs.getInt("brightness", 100);

    // initialise screen
    tft.init();
    tft.initDMA();
    tft.startWrite();
    tft.fillScreen(TFT_BLACK);
    tft.setRotation(rt);

    lv_init(); // initialise LVGL

    // setup screen
    static auto *lvDisplay = lv_display_create(screenWidth, screenHeight);
    lv_display_set_color_format(lvDisplay, LV_COLOR_FORMAT_RGB565);
    lv_display_set_flush_cb(lvDisplay, my_disp_flush);
    lv_display_set_buffers(lvDisplay, lvBuffer[0], lvBuffer[1], lvBufferSize, LV_DISPLAY_RENDER_MODE_PARTIAL);

    screenBrightness(br); // startup brightness

    make_home_screen();

    lv_scr_load(home_screen);

    Serial.print("Setup finished");
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}

void loop()
{
  try
  {
    static uint32_t lastTick = millis();
    uint32_t current = millis();
    lv_tick_inc(current - lastTick);
    lastTick = current;
    lv_timer_handler();

    checkScreenDimming();
    delay(5);
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}