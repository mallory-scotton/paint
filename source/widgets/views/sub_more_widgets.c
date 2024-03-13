/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** sub_more_widgets
*/

#include "paint.h"

void about(widget_t *wig)
{
    wig = wig;
}

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

void close_about(button_t *btn)
{
    Widgets[e_subwidget_about]->visible = false;
    btn = btn;
}

void close_shortcut(button_t *btn)
{
    Widgets[e_subwidget_shortcut]->visible = false;
    btn = btn;
}
