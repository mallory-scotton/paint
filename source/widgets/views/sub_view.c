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

static void zoom_in(button_t *btn)
{
    btn = btn;
}

static void zoom_out(button_t *btn)
{
    btn = btn;
}

static void show_it(button_t *btn)
{
    btn = btn;
    return;
}

static void view_sub_view_buttons(void)
{
    button_t **list = Widgets[e_subwidget_view]->buttons;

    button_set_sub_context(list[0], "Zoom in", VEC2(0, 0), &zoom_in);
    button_set_sub_context(list[1], "Zoom out", VEC2(0, 40), &show_it);
    button_set_sub_context(list[2], "Fit the area", VEC2(0, 80), &show_it);
    button_set_sub_context(list[3], "Pixel to pixel", VEC2(0, 120), &show_it);
}

void view_sub_view_init(void)
{
    Widgets[e_subwidget_view]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_view]->size.y = 4 * 40.0f;
    Widgets[e_subwidget_view]->position.x = 269.0f;
    Widgets[e_subwidget_view]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_view]->backgroundColor = sfWhite;
    Widgets[e_subwidget_view]->hasShadow = true;
    Widgets[e_subwidget_view]->buttonCount = 4;
    Widgets[e_subwidget_view]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_view]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_view]->buttonCount; i++) {
        Widgets[e_subwidget_view]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_view]->buttons[i]->index = i;
    }
    view_sub_view_buttons();
    Widgets[e_subwidget_view]->visible = false;
}
