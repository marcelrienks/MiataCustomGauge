#include "presenters/demo_screen.h"
#include "components/views/demo_view.h"
#include <components/models/demo_model.h>

/// @brief DemoScreen constructor, generates a scale with a needle line
DemoScreen::DemoScreen(lv_obj_t *base_screen)
{
    DemoModel *demo_model = new DemoModel();
    DemoView *demo_view = new DemoView(base_screen, demo_model);
}