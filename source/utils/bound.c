/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** bound
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Checks if the mouse pointer is within a specified rectangle.
///
/// This function determines whether the mouse pointer is inside a rectangle
/// defined by the given position and size.
///
/// \param pos The position of the top-left corner of the rectangle.
/// \param size The size of the rectangle (width and height).
///
/// \return True if the mouse pointer is inside the rectangle, false otherwise.
///
///////////////////////////////////////////////////////////////////////////////
bool mouse_in(vec2f pos, vec2f size)
{
    vec2f mp = TV2(Tool->mousePos);

    RETURN(!(mp.x >= pos.x && mp.x <= pos.x + size.x), false);
    RETURN(!(mp.y >= pos.y && mp.y <= pos.y + size.y), false);
    return (true);
}
