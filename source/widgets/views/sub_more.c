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

static void view_sub_more_buttons(void)
{
    button_t **list = Widgets[e_subwidget_more]->buttons;

    button_set_sub_context(list[0], "Theme", VEC2(0, 0), &show_it);
    button_set_sub_context(list[1], "Shortcuts", VEC2(0, 40), &show_it);
    button_set_sub_context(list[2], "About us", VEC2(0, 80), &show_it);
}

void view_sub_more_init(void)
{
    Widgets[e_subwidget_more]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_more]->size.y = 3 * 40.0f;
    Widgets[e_subwidget_more]->position.x = 434.0f;
    Widgets[e_subwidget_more]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_more]->backgroundColor = sfWhite;
    Widgets[e_subwidget_more]->buttonCount = 3;
    Widgets[e_subwidget_more]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_more]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_more]->buttonCount; i++) {
        Widgets[e_subwidget_more]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_more]->buttons[i]->index = i;
    }
    view_sub_more_buttons();
    Widgets[e_subwidget_more]->visible = false;
}
