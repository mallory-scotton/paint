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
    string tex = " Alt + scroll to zoom in or out or in the View context.\n\n";
    string te = "You can change the color by picking one on the right.\n\nYou";
    string ti = " can now do the basics ! Try other things and be creative !";

    text = my_strdcat(text, txt, tex);
    text = my_strdcat(text, te, ti);
    sfText_setFont(t, OpenSans);
    sfText_setPosition(t, Vec2.add(wig->position, VEC2(35.0f, 35.0f)));
    sfText_setString(t, text);
    sfText_setCharacterSize(t, 20);
    sfRenderWindow_drawText(Win->self, t, NULL);
    free(text);
    wig = wig;
}

void credit_text(widget_t *wig)
{
    sfText *t = sfText_create();
    string text = "Presented by Mallory Scotton and Hugo Cathealain.\n\nProje";
    string txt = "ct at Epitech in 2024 named MyPaint.\n\n\n\nmallory.scotton";
    string tex = "@epitech.eu\nhugo.cathelain@epitech.eu";

    text = my_strdcat(text, txt, tex);
    sfText_setFont(t, OpenSans);
    sfText_setPosition(t, Vec2.add(wig->position, VEC2(35.0f, 35.0f)));
    sfText_setString(t, text);
    sfText_setCharacterSize(t, 22);
    sfRenderWindow_drawText(Win->self, t, NULL);
    free(text);
    wig = wig;
}
