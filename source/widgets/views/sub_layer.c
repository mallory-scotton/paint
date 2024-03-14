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

static void view_sub_layer_buttons(void)
{
    button_t **list = Widgets[e_subwidget_layer]->buttons;

    button_set_sub_context(list[0], "New", VEC2(0, 0), &show_it);
    button_set_sub_context(list[1], "Duplicate layer", VEC2(0, 40), &show_it);
    button_set_sub_context(list[2], "Delete", VEC2(0, 80), &show_it);
    button_set_sub_context(list[3], "Group layers", VEC2(0, 120), &show_it);
}

void view_sub_layer_init(void)
{
    Widgets[e_subwidget_layer]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_layer]->size.y = 4 * 40.0f;
    Widgets[e_subwidget_layer]->position.x = 196.0f;
    Widgets[e_subwidget_layer]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_layer]->backgroundColor = sfWhite;
    Widgets[e_subwidget_layer]->cornerRadius = 0.0f;
    Widgets[e_subwidget_layer]->hasShadow = true;
    Widgets[e_subwidget_layer]->buttonCount = 4;
    Widgets[e_subwidget_layer]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_layer]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_layer]->buttonCount; i++) {
        Widgets[e_subwidget_layer]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_layer]->buttons[i]->index = i;
    }
    view_sub_layer_buttons();
    Widgets[e_subwidget_layer]->visible = false;
}
