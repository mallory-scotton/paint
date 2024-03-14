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

static void show_subwidget(button_t *btn)
{
    widget_list_t sub[7] = {e_subwidget_file, e_subwidget_edit,
        e_subwidget_image, e_subwidget_layer, e_subwidget_view,
        e_subwidget_window, e_subwidget_help};

    for (int i = 0; i < 7; i++)
        Widgets[sub[i]]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
    btn->state = e_state_clicked;
    Widgets[sub[btn->index]]->visible = true;
}

static void on_hover(button_t *btn)
{
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        if (Widgets[e_widget_context]->buttons[i]->state == e_state_clicked)
            show_subwidget(btn);
}

static void view_context_buttons(void)
{
    button_t **list = Widgets[e_widget_context]->buttons;

    button_set_context(list[0], "File", VEC2(4, 6), &show_subwidget);
    button_set_context(list[1], "Edit", VEC2(59, 6), &show_subwidget);
    button_set_context(list[2], "Image", VEC2(118, 6), &show_subwidget);
    button_set_context(list[3], "Layer", VEC2(196, 6), &show_subwidget);
    button_set_context(list[4], "View", VEC2(269, 6), &show_subwidget);
    button_set_context(list[5], "Window", VEC2(337, 6), &show_subwidget);
    button_set_context(list[6], "Help", VEC2(434, 6), &show_subwidget);
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++) {
        Widgets[e_widget_context]->buttons[i]->asHoverEvt = true;
        Widgets[e_widget_context]->buttons[i]->onHover = &on_hover;
    }
}

void view_context_init(void)
{
    Widgets[e_widget_context]->size.x = UI_CONTEXT_W;
    Widgets[e_widget_context]->size.y = UI_CONTEXT_H;
    Widgets[e_widget_context]->position.x = 0;
    Widgets[e_widget_context]->position.y = 0;
    Widgets[e_widget_context]->backgroundColor = COLOR_BASE;
    Widgets[e_widget_context]->buttonCount = 7;
    Widgets[e_widget_context]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_widget_context]->buttonCount);
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++) {
        Widgets[e_widget_context]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_widget_context]->buttons[i]->index = i;
    }
    view_context_buttons();
    Widgets[e_widget_context]->visible = true;
}
