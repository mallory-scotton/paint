/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** header
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

void dummy_click(button_t *btn)
{
    return;
}

void view_header_buttons(void)
{
    button_t **list = Widgets[e_widget_header]->buttons;

    button_set_header(list[0], "File", VEC2(4, 6), &dummy_click);
    button_set_header(list[1], "Edit", VEC2(59, 6), &dummy_click);
    button_set_header(list[2], "Image", VEC2(118, 6), &dummy_click);
    button_set_header(list[3], "Layer", VEC2(196, 6), &dummy_click);
    button_set_header(list[4], "View", VEC2(269, 6), &dummy_click);
    button_set_header(list[5], "Window", VEC2(337, 6), &dummy_click);
    button_set_header(list[6], "More", VEC2(434, 6), &dummy_click);
    button_set_header(list[7], "Help", VEC2(503, 6), &dummy_click);
}

void view_header_init(void)
{
    Widgets[e_widget_header]->size.x = WIN_WIDTH;
    Widgets[e_widget_header]->size.y = UI_TOOL_H;
    Widgets[e_widget_header]->position.x = 0;
    Widgets[e_widget_header]->position.y = 0;
    Widgets[e_widget_header]->backgroundColor = COLOR_BASE;
    Widgets[e_widget_header]->buttonCount = 8;
    Widgets[e_widget_header]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_widget_header]->buttonCount);
    for (uint i = 0; i < Widgets[e_widget_header]->buttonCount; i++) {
        Widgets[e_widget_header]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_widget_header]->buttons[i]->index = i;
    }
    view_header_buttons();
    Widgets[e_widget_header]->visible = true;
}
