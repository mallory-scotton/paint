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
    new->position = VEC2(WIN_WIDTH / 2, WIN_HEIGHT / 2);
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
/// \brief Draws a transparent grid on the canvas.
///
/// \param c Pointer to the canvas to draw on.
///
/// This function draws a transparent grid on the canvas using the specified
/// texture for transparency. It calculates the necessary parameters, such as
/// position, scale, and tile size, and then iterates over the grid, drawing
/// each tile.
///
///////////////////////////////////////////////////////////////////////////////
static void canvas_draw_transparent(canvas_t *c)
{
    sfSprite *tran = sfSprite_create();
    vec2f cover = Vec2.multiply(VEC2(c->width, c->height), c->scale.x);
    vec2f pos = VEC2(c->position.x - (c->width * c->scale.x) / 2,
        c->position.y - (c->height * c->scale.y) / 2);
    vec2i numTiles = VEC2I(cover.x / 16.0f, cover.y / 16.0f);
    vec2f tileScale = VEC2F(cover.x / (numTiles.x * 16.0f), cover.y /
        (numTiles.y * 16.0f));
    vec2f newPos;

    sfSprite_setTexture(tran, Assets[e_assets_transparent], false);
    sfSprite_setScale(tran, tileScale);
    for (int x = 0; x < numTiles.x; x++)
        for (int y = 0; y < numTiles.y; y++) {
            newPos = VEC2(pos.x + x * 16.0f * tileScale.x,
                pos.y + y * 16.0f * tileScale.y);
            sfSprite_setPosition(tran, newPos);
            DOIF(!(newPos.x < 0 || newPos.x > WIN_WIDTH || newPos.y < 0
                || newPos.y > WIN_HEIGHT), SPRITE_DRAW(tran));
        }
    sfSprite_destroy(tran);
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
    sfSprite_setScale(sc, c->scale);
    sfSprite_setOrigin(sc, VEC2(c->width / 2, c->height / 2));
    sfSprite_setPosition(sc, c->position);
    canvas_draw_transparent(c);
    sfRenderWindow_drawSprite(Win->self, sc, NULL);
    sfSprite_destroy(sc);
    sfTexture_destroy(tc);
    sfImage_destroy(ic);
}
