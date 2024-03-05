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
/// \brief Draws the background of the widget.
///
/// This function creates a rectangle shape with the widget's background color,
/// size, and position, and then draws it on the render window.
///
/// \param wid Pointer to the widget_t structure.
///
///////////////////////////////////////////////////////////////////////////////
static void widget_background_draw(widget_t *wid)
{
    sfRectangleShape *back = sfRectangleShape_create();

    sfRectangleShape_setFillColor(back, wid->backgroundColor);
    sfRectangleShape_setSize(back, wid->size);
    sfRectangleShape_setPosition(back, wid->position);
    sfRenderWindow_drawRectangleShape(Win->self, back, NULL);
    sfRectangleShape_destroy(back);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the widget.
///
/// This function draws the background of the widget, checks and sets the
/// cursor visibility, draws the buttons associated with the widget, and
/// finally calls the custom draw function if specified.
///
/// \param wid Pointer to the widget_t structure.
/// \param cursorOnWidget Pointer to the cursorOnWidget flag.
///
///////////////////////////////////////////////////////////////////////////////
void widget_draw(widget_t *wid)
{
    RETURN(!wid->visible, (void)0);
    widget_background_draw(wid);
    for (uint i = 0; i < wid->buttonCount; i++)
        button_draw(wid, wid->buttons[i]);
    DOIF(wid->hasCustomDraw, wid->customDraw(wid));
}
