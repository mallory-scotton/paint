/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** transform
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the transformation rectangle shape.
///
/// This function sets up the properties of the transformation rectangle shape,
/// including its size, fill color, outline color, outline thickness, and
/// origin.
///
/// \param t A pointer to the transformation rectangle shape.
///
///////////////////////////////////////////////////////////////////////////////
static void transform_init(sfRectangleShape *t)
{
    sfRectangleShape_setSize(t, VEC2(10, 10));
    sfRectangleShape_setFillColor(t, sfWhite);
    sfRectangleShape_setOutlineColor(t, COLOR_ACCENT);
    sfRectangleShape_setOutlineThickness(t, 1.0f);
    sfRectangleShape_setOrigin(t, VEC2(5, 5));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Renders the transformation rectangle at various positions.
///
/// This function draws the transformation rectangle shape at different
/// positions to represent its various points during a transformation process.
/// It utilizes the given size and position to render the shape accordingly.
///
/// \param t A pointer to the transformation rectangle shape.
/// \param size The size of the canvas.
/// \param pos The position of the canvas.
///
///////////////////////////////////////////////////////////////////////////////
static void transform_render(sfRectangleShape *t, vec2f size, vec2f pos)
{
    sfRectangleShape_setPosition(t, VEC2(pos.x, pos.y));
    sfRenderWindow_drawRectangleShape(Win->self, t, NULL);
    sfRectangleShape_setPosition(t, VEC2(pos.x + size.x / 2, pos.y));
    sfRenderWindow_drawRectangleShape(Win->self, t, NULL);
    sfRectangleShape_setPosition(t, VEC2(pos.x + size.x, pos.y));
    sfRenderWindow_drawRectangleShape(Win->self, t, NULL);
    sfRectangleShape_setPosition(t, VEC2(pos.x + size.x, pos.y + size.y / 2));
    sfRenderWindow_drawRectangleShape(Win->self, t, NULL);
    sfRectangleShape_setPosition(t, VEC2(pos.x + size.x, pos.y + size.y));
    sfRenderWindow_drawRectangleShape(Win->self, t, NULL);
    sfRectangleShape_setPosition(t, VEC2(pos.x + size.x / 2, pos.y + size.y));
    sfRenderWindow_drawRectangleShape(Win->self, t, NULL);
    sfRectangleShape_setPosition(t, VEC2(pos.x, pos.y + size.y));
    sfRenderWindow_drawRectangleShape(Win->self, t, NULL);
    sfRectangleShape_setPosition(t, VEC2(pos.x, pos.y + size.y / 2));
    sfRenderWindow_drawRectangleShape(Win->self, t, NULL);
    sfRectangleShape_setPosition(t, VEC2(pos.x + size.x / 2,
        pos.y + size.y / 2));
    sfRenderWindow_drawRectangleShape(Win->self, t, NULL);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the transformation rectangle on the canvas.
///
/// This function creates, initializes, renders, and then destroys the
/// transformation rectangle on the canvas. It uses the canvas's size, scale,
/// and position to determine the appropriate properties of the transformation
/// shape.
///
/// \param c A pointer to the canvas structure.
///
///////////////////////////////////////////////////////////////////////////////
void transform_draw(canvas_t *c)
{
    sfRectangleShape *t = sfRectangleShape_create();
    float w = c->width * c->scale.x;
    float h = c->height * c->scale.y;
    float x = c->position.x - w / 2;
    float y = c->position.y - h / 2;

    transform_init(t);
    transform_render(t, VEC2(w, h), VEC2(x, y));
    sfRectangleShape_destroy(t);
}
