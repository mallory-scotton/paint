/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** loop
*/
#include "paint.h"

void display_ui(void)
{
    sfVector2f pos = {-1, -1};
    sfVector2f size = {sfRenderWindow_getSize(Win->self).x, 15};

    get_rec(0.5f, pos, size);
    pos.y = sfRenderWindow_getSize(Win->self).y - 14;
    get_rec(0.5f, pos, size);
}

void loop(void)
{
    while (sfRenderWindow_isOpen(Win->self)) {
        events();
        sfRenderWindow_clear(Win->self, sfBlack);
        display_ui();
        sfRenderWindow_display(Win->self);
    }
}
