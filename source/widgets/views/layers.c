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

static void layers_custom_draw(widget_t *wid)
{
    draw_color_picker(Vec2.add(wid->position, VEC2(
        (UI_LAYERS_W - (UI_CLR_A_S + UI_CLR_R_W)) / 2, 0.0f)));
}

void view_layers_init(void)
{
    Widgets[e_widget_layers]->size.x = UI_LAYERS_W;
    Widgets[e_widget_layers]->size.y = UI_LAYERS_H;
    Widgets[e_widget_layers]->position.x = WIN_WIDTH - UI_LAYERS_W;
    Widgets[e_widget_layers]->position.y = UI_TOOL_H + UI_CONTEXT_H;
    Widgets[e_widget_layers]->backgroundColor = COLOR_BASE;
    Widgets[e_widget_layers]->buttonCount = 0;
    Widgets[e_widget_layers]->visible = true;
    Widgets[e_widget_layers]->hasCustomDraw = true;
    Widgets[e_widget_layers]->customDraw = &layers_custom_draw;
}
