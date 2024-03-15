/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** draw
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws text at the specified position.
///
/// This function creates a text object with the specified string and font,
/// sets its position, character size, color, and draws it on the window.
///
/// \param pos The position at which to draw the text.
/// \param text The text string to draw.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void draw_text(vec2f pos, string text)
{
    sfText *t = sfText_create();

    sfText_setFont(t, OpenSans);
    sfText_setString(t, text);
    sfText_setPosition(t, pos);
    sfText_setCharacterSize(t, 18);
    sfText_setFillColor(t, COLOR_TEXT);
    sfRenderWindow_drawText(Win->self, t, NULL);
    sfText_destroy(t);
}
