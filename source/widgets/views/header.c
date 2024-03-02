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

void view_header_init(void)
{
    Widgets[e_widget_header]->size.x = WIN_WIDTH;
    Widgets[e_widget_header]->size.y = UI_TOOL_H;
    Widgets[e_widget_header]->position.x = 0;
    Widgets[e_widget_header]->position.y = 0;
    Widgets[e_widget_header]->backgroundColor = COLOR_BG_BTN;
    Widgets[e_widget_header]->buttonCount = 0;
    Widgets[e_widget_header]->visible = true;
}
