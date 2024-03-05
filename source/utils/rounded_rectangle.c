/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** rounded_rectangle
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets up a rounded rectangle.
///
/// This function configures a rounded rectangle using the specified circle
/// shape, rectangle shape, fill color, and radius.
///
/// \param c The circle shape for rounded corners.
/// \param r The rectangle shape for the main body of the rounded rectangle.
/// \param fillColor The fill color of the rounded rectangle.
/// \param radius The radius of the rounded corners.
///
///////////////////////////////////////////////////////////////////////////////
static void set_rounded_rect(sfCircleShape *c, sfRectangleShape *r,
    sfColor fillColor, float radius)
{
    sfCircleShape_setRadius(c, radius);
    sfCircleShape_setFillColor(c, fillColor);
    sfCircleShape_setOrigin(c, VEC2(radius, radius));
    sfRectangleShape_setFillColor(r, fillColor);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the fillers of a rounded rectangle.
///
/// This function draws the horizontal and vertical fillers of a rounded
/// rectangle using the specified rectangle shape, size, position, and radius.
///
/// \param r The rectangle shape used for drawing fillers.
/// \param size The size of the rounded rectangle.
/// \param pos The position of the rounded rectangle.
/// \param radius The radius of the rounded corners.
///
///////////////////////////////////////////////////////////////////////////////
static void draw_fillers(sfRectangleShape *r, vec2f size, vec2f pos,
    float radius)
{
    sfRectangleShape_setSize(r, VEC2(size.x - radius * 2, size.y));
    sfRectangleShape_setPosition(r, VEC2(pos.x + radius, pos.y));
    sfRenderWindow_drawRectangleShape(Win->self, r, NULL);
    sfRectangleShape_setSize(r, VEC2(size.x, size.y - radius * 2));
    sfRectangleShape_setPosition(r, VEC2(pos.x, pos.y + radius));
    sfRenderWindow_drawRectangleShape(Win->self, r, NULL);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the corners of a rounded rectangle.
///
/// This function draws the four corners of a rounded rectangle using the
/// specified circle shape, size, position, and radius.
///
/// \param c The circle shape used for drawing corners.
/// \param size The size of the rounded rectangle.
/// \param pos The position of the rounded rectangle.
/// \param radius The radius of the rounded corners.
///
///////////////////////////////////////////////////////////////////////////////
static void draw_corners(sfCircleShape *c, vec2f size, vec2f pos,
    float radius)
{
    sfCircleShape_setPosition(c, VEC2(pos.x + radius, pos.y + radius));
    sfRenderWindow_drawCircleShape(Win->self, c, NULL);
    sfCircleShape_setPosition(c, VEC2(pos.x + size.x - radius, pos.y +
        radius));
    sfRenderWindow_drawCircleShape(Win->self, c, NULL);
    sfCircleShape_setPosition(c, VEC2(pos.x + radius, pos.y + size.y -
        radius));
    sfRenderWindow_drawCircleShape(Win->self, c, NULL);
    sfCircleShape_setPosition(c, VEC2(pos.x + size.x - radius, pos.y + size.y
        - radius));
    sfRenderWindow_drawCircleShape(Win->self, c, NULL);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws a rounded rectangle.
///
/// This function draws a rounded rectangle on the window using the specified
/// size, position, fill color, and corner radius.
///
/// \param size The size of the rounded rectangle.
/// \param pos The position of the rounded rectangle.
/// \param fillColor The fill color of the rounded rectangle.
/// \param radius The radius of the rounded corners.
///
///////////////////////////////////////////////////////////////////////////////
void draw_rounded_rectangle(vec2f size, vec2f pos, sfColor fillColor,
    float radius)
{
    sfCircleShape *c = sfCircleShape_create();
    sfRectangleShape *r = sfRectangleShape_create();

    set_rounded_rect(c, r, fillColor, radius);
    draw_corners(c, size, pos, radius);
    draw_fillers(r, size, pos, radius);
    sfCircleShape_destroy(c);
    sfRectangleShape_destroy(r);
}
