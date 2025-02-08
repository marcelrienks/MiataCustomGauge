#include <ticker.h>

/// @brief Handle timers using tickers and calculating the time differences since start up
void Ticker::HandleTimers() {
    static uint32_t lastTick = millis();
    uint32_t current = millis();
    lv_tick_inc(current - lastTick);
    lastTick = current;
    lv_timer_handler();
}