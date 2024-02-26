/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** event
*/
#include "paint.h"

static void parse_event(sfEvent evt)
{
    DOIF(evt.type == sfEvtClosed, sfRenderWindow_close(Win->self));
}

void events(void)
{
    sfEvent evt;

    while (sfRenderWindow_pollEvent(Win->self, &evt))
        parse_event(evt);
}
