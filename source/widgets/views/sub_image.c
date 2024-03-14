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

static void view_sub_image_buttons(void)
{
    button_t **list = Widgets[e_subwidget_image]->buttons;

    button_set_sub_context(list[0], "Canva size...", VEC2(0, 0), &show_it);
    button_set_sub_context(list[1], "Image size...", VEC2(0, 40), &show_it);
    button_set_sub_context(list[2], "Transform", VEC2(0, 80), &show_it);
    button_set_sub_context(list[3], "Reveal all", VEC2(0, 120), &show_it);
    button_set_sub_context(list[4], "Duplicate", VEC2(0, 160), &show_it);
}

void view_sub_image_init(void)
{
    Widgets[e_subwidget_image]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_image]->size.y = 200;
    Widgets[e_subwidget_image]->position.x = 118.0f;
    Widgets[e_subwidget_image]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_image]->backgroundColor = sfWhite;
    Widgets[e_subwidget_image]->cornerRadius = 0.0f;
    Widgets[e_subwidget_image]->hasShadow = true;
    Widgets[e_subwidget_image]->buttonCount = 5;
    Widgets[e_subwidget_image]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_image]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_image]->buttonCount; i++) {
        Widgets[e_subwidget_image]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_image]->buttons[i]->index = i;
    }
    view_sub_image_buttons();
    Widgets[e_subwidget_image]->visible = false;
}
