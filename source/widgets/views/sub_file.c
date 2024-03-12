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
    return;
}

static void view_sub_file_buttons(void)
{
    button_t **list = Widgets[e_subwidget_file]->buttons;

    button_set_sub_context(list[0], TXT_NW, VEC2(4, 6), &show_it);
    button_set_sub_context(list[1], TXT_OP, VEC2(4, 46), &show_it);
    button_set_sub_context(list[2], TXT_SV, VEC2(4, 86), &show_it);
    button_set_sub_context(list[3], TXT_SA, VEC2(4, 126), &show_it);
    button_set_sub_context(list[4], TXT_EA, VEC2(4, 166), &show_it);
}

void view_sub_file_init(void)
{
    Widgets[e_subwidget_file]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_file]->size.y = 210;
    Widgets[e_subwidget_file]->position.x = 4.0f;
    Widgets[e_subwidget_file]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_file]->backgroundColor = sfWhite;
    Widgets[e_subwidget_file]->buttonCount = 5;
    Widgets[e_subwidget_file]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_file]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_file]->buttonCount; i++) {
        Widgets[e_subwidget_file]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_file]->buttons[i]->index = i;
    }
    view_sub_file_buttons();
    Widgets[e_subwidget_file]->visible = false;
}
