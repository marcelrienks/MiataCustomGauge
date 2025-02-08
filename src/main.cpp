#define LGFX_USE_V1

#include "main.h"

// TODO: external class
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

      cfg.memory_width = SCREEN_WIDTH;
      cfg.memory_height = SCREEN_HEIGHT;
      cfg.panel_width = SCREEN_WIDTH;
      cfg.panel_height = SCREEN_HEIGHT;
      cfg.offset_x = SCREEN_OFFSET_X;
      cfg.offset_y = SCREEN_OFFSET_Y;
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = false;
      cfg.rgb_order = SCREEN_RGB_ORDER;
      cfg.dlen_16bit = false;
      cfg.bus_shared = false;

#ifdef RELEASE
      cfg.invert = true;
#endif

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

LGFX device;
Preferences preferences;

// TODO: pull this out into a static class
//  Constants
lv_color_t black = lv_color_make(0, 0, 0);

// TODO: convert this to a class object, with lv_obj_t and custom screen functions below
//  Screens
lv_obj_t *screen;

// Components
Meter *meter;

const unsigned int lvBufferSize = SCREEN_WIDTH * 10;
uint8_t lvBuffer[2][lvBufferSize];

void set_needle_line_value(void *obj, int32_t v)
{
  meter->set_needle_line_value(obj, v);
}

void screenBrightness(uint8_t value)
{
  device.setBrightness(value);
}

// TODO: Can this be put in an external class?
void my_disp_flush(lv_display_t *display, const lv_area_t *area, unsigned char *data)
{
  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);
  lv_draw_sw_rgb565_swap(data, w * h);

  if (device.getStartCount() == 0)
  {
    device.endWrite();
  }

  device.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (uint16_t *)data);
  lv_disp_flush_ready(display);
}

void setup()
{
  try
  {
    Serial.begin(115200);

    // Initialise screen
    device.init();
    device.initDMA();
    device.startWrite();
    device.fillScreen(TFT_BLACK);
    device.setRotation(preferences.getInt("rotate", 0));

    lv_init();

    // setup screen
    static auto *lvDisplay = lv_display_create(SCREEN_WIDTH, SCREEN_HEIGHT);
    lv_display_set_color_format(lvDisplay, LV_COLOR_FORMAT_RGB565);
    lv_display_set_flush_cb(lvDisplay, my_disp_flush);
    lv_display_set_buffers(lvDisplay, lvBuffer[0], lvBuffer[1], lvBufferSize, LV_DISPLAY_RENDER_MODE_PARTIAL);

    screenBrightness(SCREEN_DEFAULT_BRIGHTNESS);

    screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, black, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, LV_PART_MAIN);

    // init Meter
    meter = new Meter(screen);
    meter->register_animation_cb(set_needle_line_value);
    meter->build();

    lv_scr_load(screen);

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
    // TODO: refactor this to use a global variable and an external function call
    static uint32_t lastTick = millis();
    uint32_t current = millis();
    lv_tick_inc(current - lastTick);
    lastTick = current;
    lv_timer_handler();

    delay(5);
  }
  catch (const std::exception &e)
  {
    Serial.println(e.what());
    throw;
  }
}