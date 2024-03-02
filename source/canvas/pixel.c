/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** pixel
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Get the pixel color at x, y
///
/// \param x The x coordinate of the pixel
/// \param y The y coordiante of the pixel
///
/// \return The color of the pixel
///
///////////////////////////////////////////////////////////////////////////////
sfColor getpixel(int x, int y)
{
    canvas_t *c = Tool->canva;
    ulong idx = 0;

    if (x >= 0 && x < (int)c->width && y >= 0 && y < (int)c->height) {
        idx = (ulong)(x + y * c->width) * 4;
        return (sfColor_fromRGBA(c->pixels[idx], c->pixels[idx + 1],
            c->pixels[idx + 2], c->pixels[idx + 3]));
    }
    return (sfBlack);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Set the color of a pixel
///
/// \param x The x coordinate of the pixel
/// \param y The y coordinate of the pixel
/// \param color The color to set for the pixel
///
///////////////////////////////////////////////////////////////////////////////
void setpixel(int x, int y, sfColor color)
{
    canvas_t *c = Tool->canva;
    ulong idx = 0;

    if (x >= 0 && x < (int)c->width && y >= 0 && y < (int)c->height) {
        idx = (ulong)(x + y * c->width) * 4;
        c->pixels[idx] = color.r;
        c->pixels[idx + 1] = color.g;
        c->pixels[idx + 2] = color.b;
        c->pixels[idx + 3] = color.a;
    }
}
