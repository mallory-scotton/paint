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

void fit_area(button_t *btn)
{
    float max_width = WIN_WIDTH - UI_TOOLBAR_W - UI_LAYERS_W - 100;
    float max_height = WIN_HEIGHT - UI_CONTEXT_H - UI_TOOL_H - 100;
    float calculus = max_width / Tool->canva->width;
    float decalcul = max_height / Tool->canva->height;
    float scale = calculus < decalcul ? calculus : decalcul;

    Widgets[e_subwidget_view]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
    Tool->canva->scale = VEC2(scale, scale);
    Tool->canva->position = VEC2((max_width / 2.0f) + UI_TOOLBAR_W + 50,
        (max_height / 2.0f) + UI_CONTEXT_H + UI_TOOL_H + 50);
    btn = btn;
}

void zoom_in(button_t *btn)
{
    Tool->canva->scale = get_scale_factor(0.3f, Tool->canva->scale);
    btn = btn;
}

void zoom_out(button_t *btn)
{
    Tool->canva->scale = get_scale_factor(-0.3f, Tool->canva->scale);
    btn = btn;
}

void pixel(button_t *btn)
{
    Widgets[e_subwidget_view]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
    Tool->canva->scale = VEC2(1.0f, 1.0f);
    btn = btn;
}

static void view_sub_view_buttons(void)
{
    button_t **list = Widgets[e_subwidget_view]->buttons;

    button_set_sub_context(list[0], "Zoom in", VEC2(0, 0), &zoom_in);
    button_set_sub_context(list[1], "Zoom out", VEC2(0, 40), &zoom_out);
    button_set_sub_context(list[2], "Fit the area", VEC2(0, 80), &fit_area);
    button_set_sub_context(list[3], "Pixel to pixel", VEC2(0, 120), &pixel);
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
