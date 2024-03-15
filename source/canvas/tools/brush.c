/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** brush
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Blends two colors with a specified transparency.
///
/// This function blends two colors with a specified transparency level and
/// returns the resulting color.
///
/// \param c1 The first color to blend.
/// \param c2 The second color to blend.
/// \param transparency The transparency level of the blending (0.0 to 1.0).
///
/// \return The blended color.
///
///////////////////////////////////////////////////////////////////////////////
sfColor blend(sfColor c1, sfColor c2, float transparency)
{
    uchar alpha = (uchar)(c1.a * transparency + c2.a * (1.0f - transparency));
    uchar red = (uchar)(c1.r * transparency + c2.r * (1.0f - transparency));
    uchar green = (uchar)(c1.g * transparency + c2.g * (1.0f - transparency));
    uchar blue = (uchar)(c1.b * transparency + c2.b * (1.0f - transparency));

    return sfColor_fromRGBA(red, green, blue, alpha);
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
    float dist;
    float trans;
    sfColor currentColor;
    sfColor blendedColor;

    for (int i = (int)x - r; i <= (int)x + r; ++i) {
        for (int j = (int)y - r; j <= (int)y + r; ++j) {
            dist = sqrtf(SQUARE(i - x) + SQUARE(j - y));
            trans = fmaxf(0.0f, fminf(1.0f, (1.0f - (dist / (float)(r)))));
            currentColor = getpixel(i, j);
            blendedColor = blend(Tool->color, currentColor, trans);
            setpixel(i, j, blend_colors(blendedColor, currentColor));
        }
    }
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
/// \brief Handles drawing using the brush tool.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void use_brush_tool(void)
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
