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

/// Pointer to the active canvas list.
canvas_t *Canvas;

///////////////////////////////////////////////////////////////////////////////
/// \brief Adds a new canvas to the paint application.
///
/// \param width The width of the new canvas.
/// \param height The height of the new canvas.
/// \param name The name of the new canvas.
/// \param baseColor The base color of the new canvas.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void canvas_add(uint width, uint height, string name, sfColor baseColor)
{
    canvas_t *new = malloc(sizeof(canvas_t));

    new->height = height;
    new->width = width;
    new->name = name;
    new->saved = false;
    new->path = NULL;
    new->baseColor = baseColor;
    new->position = VEC2(200.0f, 200.0f);
    new->scale = VEC2(1.0f, 1.0f);
    new->pixels = malloc(sizeof(sfUint8) * (width * height * 4));
    new->next = Canvas;
    for (ulong i = 0; i < (width * height * 4); i += 4) {
        new->pixels[i] = baseColor.r;
        new->pixels[i + 1] = baseColor.g;
        new->pixels[i + 2] = baseColor.g;
        new->pixels[i + 3] = baseColor.a;
    }
    Canvas = new;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the active canvas on the window.
///
/// \param c Pointer to the canvas to be drawn.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void canvas_draw(canvas_t *c)
{
    sfImage *ic = sfImage_createFromPixels(c->width, c->height, c->pixels);
    sfTexture *tc = sfTexture_createFromImage(ic, NULL);
    sfSprite *sc = sfSprite_create();

    sfSprite_setTexture(sc, tc, false);
    sfSprite_setColor(sc, sfColor_fromRGBA(0, 0, 0, 58));
    sfSprite_setPosition(sc, VEC2(c->position.x - 5, c->position.y + 5));
    sfSprite_setScale(sc, c->scale);
    sfRenderWindow_drawSprite(Win->self, sc, NULL);
    sfSprite_setPosition(sc, c->position);
    sfSprite_setColor(sc, sfColor_fromRGBA(255, 255, 255, 255));
    sfRenderWindow_drawSprite(Win->self, sc, NULL);
    sfSprite_destroy(sc);
    sfTexture_destroy(tc);
    sfImage_destroy(ic);
}
