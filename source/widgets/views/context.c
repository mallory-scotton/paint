/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** context
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

void dummy_click(button_t *btn)
{
    return;
}

void view_context_buttons(void)
{
    button_t **list = Widgets[e_widget_context]->buttons;

    button_set_context(list[0], "File", VEC2(4, 6), &dummy_click);
    button_set_context(list[1], "Edit", VEC2(59, 6), &dummy_click);
    button_set_context(list[2], "Image", VEC2(118, 6), &dummy_click);
    button_set_context(list[3], "Layer", VEC2(196, 6), &dummy_click);
    button_set_context(list[4], "View", VEC2(269, 6), &dummy_click);
    button_set_context(list[5], "Window", VEC2(337, 6), &dummy_click);
    button_set_context(list[6], "More", VEC2(434, 6), &dummy_click);
    button_set_context(list[7], "Help", VEC2(503, 6), &dummy_click);
}

void view_context_init(void)
{
    Widgets[e_widget_context]->size.x = UI_CONTEXT_W;
    Widgets[e_widget_context]->size.y = UI_CONTEXT_H;
    Widgets[e_widget_context]->position.x = 0;
    Widgets[e_widget_context]->position.y = 0;
    Widgets[e_widget_context]->backgroundColor = COLOR_BASE;
    Widgets[e_widget_context]->buttonCount = 8;
    Widgets[e_widget_context]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_widget_context]->buttonCount);
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++) {
        Widgets[e_widget_context]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_widget_context]->buttons[i]->index = i;
    }
    view_context_buttons();
    Widgets[e_widget_context]->visible = true;
}
