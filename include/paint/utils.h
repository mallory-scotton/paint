/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "paint/types.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Count the number of entries in a directory.
///
/// \param path The path of the directory.
///
/// \return The number of entries in the directory.
///
///////////////////////////////////////////////////////////////////////////////
u8 dircount(cstring path);

///////////////////////////////////////////////////////////////////////////////
/// \brief Retrieves the content of a directory.
///
/// \param path The path of the directory.
///
/// \return An array containing the names of the files and directories in the
///         specified path.
///
///////////////////////////////////////////////////////////////////////////////
warray dircontent(cstring path);

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
    float radius);

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
bool mouse_in(vec2f pos, vec2f size);

#endif /* !UTILS_H_ */
