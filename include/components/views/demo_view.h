#ifndef DEMO_VIEW_H
#define DEMO_VIEW_H

#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <misc/lv_types.h>
#include <components/models/demo_model.h>

class DemoView
{
private:
    lv_obj_t *_base_screen;

public:
    DemoView(lv_obj_t *base_screen, DemoModel *demo_model);
    ~DemoView();
};

#endif // DEMO_VIEW_H