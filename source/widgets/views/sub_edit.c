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

static void view_sub_edit_buttons(void)
{
    button_t **list = Widgets[e_subwidget_edit]->buttons;

    button_set_sub_context(list[0], "Undo", VEC2(0, 0), &show_it);
    button_set_sub_context(list[1], "Redo", VEC2(0, 40), &show_it);
    button_set_sub_context(list[2], "Cut", VEC2(0, 80), &show_it);
    button_set_sub_context(list[3], "Copy", VEC2(0, 120), &show_it);
    button_set_sub_context(list[4], "Paste", VEC2(0, 160), &show_it);
    button_set_sub_context(list[5], "Clear", VEC2(0, 200), &show_it);
    button_set_sub_context(list[6], "Preferences...", VEC2(0, 240), &show_it);
    list[0]->subText = my_strdup("CTRL+Z");
    list[1]->subText = my_strdup("CTRL+Y");
    list[2]->subText = my_strdup("CTRL+X");
    list[3]->subText = my_strdup("CTRL+C");
    list[5]->subText = my_strdup("CTRL+V");
    list[6]->subText = my_strdup("Delete");
}

void view_sub_edit_init(void)
{
    Widgets[e_subwidget_edit]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_edit]->size.y = 7 * 40.f;
    Widgets[e_subwidget_edit]->position.x = 59.0f;
    Widgets[e_subwidget_edit]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_edit]->backgroundColor = sfWhite;
    Widgets[e_subwidget_edit]->hasShadow = true;
    Widgets[e_subwidget_edit]->buttonCount = 7;
    Widgets[e_subwidget_edit]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_edit]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_edit]->buttonCount; i++) {
        Widgets[e_subwidget_edit]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_edit]->buttons[i]->index = i;
    }
    view_sub_edit_buttons();
    Widgets[e_subwidget_edit]->visible = false;
}
