#include <device.h>

Device::Device(void)
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

void Device::Init()
{
    // Initialise screen
    init();
    initDMA();
    startWrite();
    fillScreen(TFT_BLACK);
    setRotation(0);
}

Device::~Device()
{
    // TODO: anything that was instantiated here using 'new' must be deleted
}