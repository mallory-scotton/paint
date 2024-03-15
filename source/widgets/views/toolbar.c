/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** toolbar
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Switches the active tool based on the clicked toolbar button.
///
/// This function is responsible for handling the click event on a toolbar
/// button, changing the state of the buttons accordingly, and updating the
/// active tool based on the selected button.
///
/// \param btn The button that was clicked on the toolbar.
///
///////////////////////////////////////////////////////////////////////////////
static void switch_tool(button_t *btn)
{
    button_t **list = Widgets[e_widget_toolbar]->buttons;
    int tools[12] = {e_tool_move, e_tool_rectangle_select, e_tool_lasso,
        e_tool_eyedropper, e_tool_pencil, e_tool_brush, e_tool_eraser,
        e_tool_bucket, e_tool_text, e_tool_rectangle, e_tool_hand,
        e_tool_zoom};

    for (uint i = 0; i < Widgets[e_widget_toolbar]->buttonCount; i++)
        if (list[i]->state != e_state_disabled)
            list[i]->state = e_state_active;
    btn->state = e_state_clicked;
    Tool->type = tools[btn->index];
    Tool->toolTexture = btn->icon;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Placeholder function for a virtual key on the toolbar.
///
/// This function serves as a placeholder for handling the click event on a
/// virtual key button in the toolbar. It can be extended for future use.
///
/// \param btn The virtual key button that was clicked.
///
///////////////////////////////////////////////////////////////////////////////
static void virtual_key(button_t *btn)
{
    btn = btn;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes and sets up the appearance of the toolbar buttons.
///
/// This function configures the appearance and behavior of each button on the
/// toolbar, including setting icons, positions, and click event handlers.
/// It also initializes the default active tool and virtual key.
///
///////////////////////////////////////////////////////////////////////////////
static void view_toolbar_buttons(void)
{
    button_t **list = Widgets[e_widget_toolbar]->buttons;
    int btns[12] = {e_assets_tool_move, e_assets_tool_rectangle_select,
        e_assets_tool_lasso, e_assets_tool_eyedropper, e_assets_tool_pencil,
        e_assets_tool_brush, e_assets_tool_eraser, e_assets_tool_bucket,
        e_assets_tool_text, e_assets_tool_rectangle, e_assets_tool_hand,
        e_assets_tool_zoom};

    for (uint i = 0; i < 12; i++)
        button_set_toolbar(list[i], Assets[btns[i]], VEC2(UI_PAD,
            UI_PAD + (UI_TOOL_H + UI_PAD / 2) * i), &switch_tool);
    list[4]->state = e_state_clicked;
    button_set_toolbar(list[12], Assets[e_assets_virtual_key],
        VEC2(UI_PAD, UI_PAD + (UI_TOOL_H + UI_PAD / 2) * 12), &virtual_key);
    list[0]->state = e_state_disabled;
    list[1]->state = e_state_disabled;
    list[2]->state = e_state_disabled;
    list[8]->state = e_state_disabled;
    list[9]->state = e_state_disabled;
    list[10]->state = e_state_disabled;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the toolbar widget and its buttons.
///
/// This function sets up the toolbar widget by defining its size, position,
/// background color, and visibility. It also creates and configures the
/// individual buttons on the toolbar.
///
///////////////////////////////////////////////////////////////////////////////
void view_toolbar_init(void)
{
    Widgets[e_widget_toolbar]->size.x = UI_TOOLBAR_W;
    Widgets[e_widget_toolbar]->size.y = UI_TOOLBAR_H;
    Widgets[e_widget_toolbar]->position.x = 0;
    Widgets[e_widget_toolbar]->position.y = UI_TOOL_H + UI_CONTEXT_H;
    Widgets[e_widget_toolbar]->cornerRadius = 0.0f;
    Widgets[e_widget_toolbar]->backgroundColor = COLOR_BASE;
    Widgets[e_widget_toolbar]->buttonCount = 13;
    Widgets[e_widget_toolbar]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_widget_toolbar]->buttonCount);
    for (uint i = 0; i < Widgets[e_widget_toolbar]->buttonCount; i++) {
        Widgets[e_widget_toolbar]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_widget_toolbar]->buttons[i]->index = i;
    }
    view_toolbar_buttons();
    Widgets[e_widget_toolbar]->visible = true;
}
