/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** rectangle
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

void get_rec(float thick, sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *rec = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rec, sfTransparent);
    sfRectangleShape_setOutlineColor(rec, sfWhite);
    sfRectangleShape_setPosition(rec, pos);
    sfRectangleShape_setSize(rec, size);
    sfRectangleShape_setOutlineThickness(rec, thick);
    sfRenderWindow_drawRectangleShape(Win->self, rec, NULL);
    sfRectangleShape_destroy(rec);
}
