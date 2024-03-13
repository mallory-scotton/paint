/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** sub_help_widget
*/

#include "paint.h"

void view_sub_tuto_buttons(void)
{
    button_t **list = Widgets[e_subwidget_tuto]->buttons;

    button_set_close(list[0], "X", VEC2(770, 0), &close_tuto);
}

void tutorial(widget_t *wig)
{
    sfText *t = sfText_create();
    string text = "You can use the pencil to draw.\n\nYou can use the eraser ";
    string txt = "to erase.\n\nYou can use the bucket to fill.\n\nYou can use";
    string tex = " Alt + scroll to zoom in or out.";

    text = my_strdcat(text, txt, tex);
    sfText_setFont(t, OpenSans);
    sfText_setPosition(t, Vec2.add(wig->position, VEC2(30.0f, 30.0f)));
    sfText_setString(t, text);
    sfText_setCharacterSize(t, 20);
    sfRenderWindow_drawText(Win->self, t, NULL);
    wig = wig;
}
