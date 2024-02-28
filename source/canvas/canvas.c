/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** canvas
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

canvas_t *Canvas;

void canvas_add(uint width, uint height, string name)
{
    canvas_t *new = malloc(sizeof(canvas_t));

    new->height = height;
    new->width = width;
    new->name = name;
    new->saved = false;
    new->path = NULL;
    new->pixels = malloc(sizeof(sfUint8) * (width * height * 4));
    new->next = Canvas;
    for (ulong i = 0; i < (width * height * 4); i++)
        new->pixels[i] = 255;
    Canvas = new;
}

void canvas_draw(canvas_t *c, vec2f pos, vec2f scale)
{
    sfImage *ic = sfImage_createFromPixels(c->width, c->height, c->pixels);
    sfTexture *tc = sfTexture_createFromImage(ic, NULL);
    sfSprite *sc = sfSprite_create();

    sfSprite_setTexture(sc, tc, false);
    sfSprite_setColor(sc, sfColor_fromRGBA(0, 0, 0, 58));
    sfSprite_setOrigin(sc, VEC2(c->width / 2, c->height / 2));
    sfSprite_setPosition(sc, VEC2(pos.x - 5, pos.y + 5));
    sfSprite_setScale(sc, scale);
    sfRenderWindow_drawSprite(Win->self, sc, NULL);
    sfSprite_setPosition(sc, pos);
    sfSprite_setColor(sc, sfColor_fromRGBA(255, 255, 255, 255));
    sfRenderWindow_drawSprite(Win->self, sc, NULL);
    sfSprite_destroy(sc);
    sfTexture_destroy(tc);
    sfImage_destroy(ic);
}
