#ifndef DEMO_MODEL_H
#define DEMDEMO_MODEL_HO_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_event.h>

class DemoModel
{
public:
    lv_obj_t *_needle_line;

    DemoModel();
    ~DemoModel();
};

#endif // DEMO_MODEL_H