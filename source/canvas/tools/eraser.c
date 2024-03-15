/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** eraser
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws a circular pattern of points around a specified point.
///
/// This function is a helper function used by the draw_pts function to draw
/// points in a circular pattern.
///
/// \param x The x-coordinate of the center point.
/// \param y The y-coordinate of the center point.
/// \param i The current x-coordinate of the point in the loop.
/// \param j The current y-coordinate of the point in the loop.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void draw_pts_loop(int x, int y, int i, int j)
{
    canvas_t *c = Tool->canva;
    int r = (Tool->thickness / 2) == 0 ? 1 : (Tool->thickness / 2);

    RETURN(!(SQUARE(i - x) + SQUARE(j - y) <= SQUARE(r)), (void)0);
    RETURN(!(i >= 0 && i < (int)(c->width) &&
        j >= 0 && j < (int)(c->height)), (void)0);
    setpixel(i, j, sfTransparent);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws points in a circular pattern around a specified point.
///
/// This function is used for drawing points in a circular pattern around a
/// specified point with the given thickness using the Bresenham's line
/// algorithm.
///
/// \param x The x-coordinate of the center point.
/// \param y The y-coordinate of the center point.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void draw_pts(int x, int y)
{
    int r = (Tool->thickness / 2) == 0 ? 1 : (Tool->thickness / 2);

    for (int i = x - r; i <= x + r; ++i)
        for (int j = y - r; j <= y + r; ++j)
            draw_pts_loop(x, y, i, j);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws a line using the Bresenham's line algorithm.
///
/// This function draws a line on the active canvas using the Bresenham's line
/// algorithm. It takes two points as input and calculates the points on the
/// line using the algorithm.
///
/// \param x0 The x-coordinate of the starting point.
/// \param y0 The y-coordinate of the starting point.
/// \param x1 The x-coordinate of the ending point.
/// \param y1 The y-coordinate of the ending point.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void bresenham_line(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (true) {
        draw_pts(x0, y0);
        RETURN((x0 == x1) && (y0 == y1), (void)0);
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Handles drawing using the eraser tool.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void use_eraser_tool(void)
{
    canvas_t *c = Tool->canva;
    vec2f pos = VEC2(Tool->canva->position.x - ((c->width * c->scale.x) / 2),
        c->position.y - ((c->height * c->scale.y) / 2));
    vec2f start = Vec2.subtract(TV2(Tool->oldMousePos), pos);
    vec2f end = Vec2.subtract(TV2(Tool->mousePos), pos);

    start = Vec2.divide(start, Tool->canva->scale.x);
    end = Vec2.divide(end, Tool->canva->scale.x);
    bresenham_line((int)start.x, (int)start.y, (int)end.x, (int)end.y);
}
