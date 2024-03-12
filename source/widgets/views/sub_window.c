/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** sub_file
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

static void show_it(button_t *btn)
{
    btn = btn;
    return;
}

static void view_sub_window_buttons(void)
{
    button_t **list = Widgets[e_subwidget_window]->buttons;

    button_set_sub_context(list[0], "Layers", VEC2(0, 0), &show_it);
    button_set_sub_context(list[1], "Toolbar", VEC2(0, 40), &show_it);
    button_set_sub_context(list[2], "Colors", VEC2(0, 80), &show_it);
}

void view_sub_window_init(void)
{
    Widgets[e_subwidget_window]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_window]->size.y = 3 * 40.0f;
    Widgets[e_subwidget_window]->position.x = 337.0f;
    Widgets[e_subwidget_window]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_window]->backgroundColor = sfWhite;
    Widgets[e_subwidget_window]->hasShadow = true;
    Widgets[e_subwidget_window]->buttonCount = 3;
    Widgets[e_subwidget_window]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_window]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_window]->buttonCount; i++) {
        Widgets[e_subwidget_window]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_window]->buttons[i]->index = i;
    }
    view_sub_window_buttons();
    Widgets[e_subwidget_window]->visible = false;
}
