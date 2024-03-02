/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** tool_option
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

void view_tool_option_init(void)
{
    Widgets[e_widget_tool_option]->size.x = WIN_WIDTH;
    Widgets[e_widget_tool_option]->size.y = UI_TOOL_H;
    Widgets[e_widget_tool_option]->position.x = 0;
    Widgets[e_widget_tool_option]->position.y = UI_TOOL_H;
    Widgets[e_widget_tool_option]->backgroundColor = COLOR_BG_BTN;
    Widgets[e_widget_tool_option]->buttonCount = 0;
    Widgets[e_widget_tool_option]->visible = true;
}
