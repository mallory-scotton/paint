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

void shortcut(widget_t *wig)
{
    sfText *t = sfText_create();
    string text = "' Alt ' + scroll  =>  zoom in / zoom out\n' Ctrl ' + scrol";
    string txt = "l  =>  move horizontaly\n' + '  =>  augment size of tool\n'";
    string tex = " - '  =>  reduce size of tool";

    text = my_strdcat(text, txt, tex);
    sfText_setFont(t, OpenSans);
    sfText_setPosition(t, Vec2.add(wig->position, VEC2(35.0f, 35.0f)));
    sfText_setString(t, text);
    sfText_setCharacterSize(t, 22);
    sfRenderWindow_drawText(Win->self, t, NULL);
    free(text);
    wig = wig;
}

void close_shortcut(button_t *btn)
{
    Widgets[e_subwidget_shortcut]->visible = false;
    btn = btn;
}

void shortcut_open(button_t *btn)
{
    Widgets[e_subwidget_shortcut]->visible = true;
    Widgets[e_subwidget_help]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
    btn = btn;
}

void view_sub_shortcut_buttons(void)
{
    button_t **list = Widgets[e_subwidget_shortcut]->buttons;

    button_set_close(list[0], "X", VEC2(770, 0), &close_shortcut);
}

void view_sub_shortcut_init(void)
{
    Widgets[e_subwidget_shortcut]->size.x = 800.0f;
    Widgets[e_subwidget_shortcut]->size.y = 400.0f;
    Widgets[e_subwidget_shortcut]->position.x = 400.0f;
    Widgets[e_subwidget_shortcut]->position.y = 300.0f;
    Widgets[e_subwidget_shortcut]->backgroundColor = COLOR_BASE;
    Widgets[e_subwidget_shortcut]->hasShadow = true;
    Widgets[e_subwidget_shortcut]->buttonCount = 1;
    Widgets[e_subwidget_shortcut]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_shortcut]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_shortcut]->buttonCount; i++) {
        Widgets[e_subwidget_shortcut]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_shortcut]->buttons[i]->index = i;
    }
    view_sub_shortcut_buttons();
    Widgets[e_subwidget_shortcut]->hasCustomDraw = true;
    Widgets[e_subwidget_shortcut]->customDraw = &shortcut;
    Widgets[e_subwidget_shortcut]->visible = false;
}
