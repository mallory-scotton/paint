/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** layers
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

void view_layers_init(void)
{
    Widgets[e_widget_layers]->size.x = UI_LAYERS_W;
    Widgets[e_widget_layers]->size.y = UI_LAYERS_H;
    Widgets[e_widget_layers]->position.x = WIN_WIDTH - UI_LAYERS_W;
    Widgets[e_widget_layers]->position.y = UI_TOOL_H + UI_HEADER_H;
    Widgets[e_widget_layers]->backgroundColor = COLOR_BASE;
    Widgets[e_widget_layers]->buttonCount = 0;
    Widgets[e_widget_layers]->visible = true;
}
