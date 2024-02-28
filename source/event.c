/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** event
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Parses mouse events and updates the state accordingly.
///
/// \param evt The SFML event to be parsed.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void parse_mouse_events(sfEvent evt)
{
    DOIF(evt.type == sfEvtClosed, sfRenderWindow_close(Win->self));
    if (evt.type == sfEvtMouseButtonPressed)
        DOIF(evt.mouseButton.button == sfMouseLeft,
            EQ2(Tool->mousePressed, true));
    if (evt.type == sfEvtMouseButtonReleased)
        DOIF(evt.mouseButton.button == sfMouseLeft,
            EQ2(Tool->mousePressed, 0));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Parses keyboard events and updates the state accordingly.
///
/// \param evt The SFML event to be parsed.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void parse_keyboard_events(sfEvent evt)
{
    if (evt.type == sfEvtKeyPressed) {
        if (evt.key.code == sfKeyAdd)
            Tool->thickness++;
        if (evt.key.code == sfKeySubtract)
            Tool->thickness--;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Handles various events, updating the tool state.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void events(void)
{
    sfEvent evt;

    Tool->oldMousePos = Tool->mousePos;
    Tool->mousePos = sfMouse_getPositionRenderWindow(Win->self);
    while (sfRenderWindow_pollEvent(Win->self, &evt)) {
        parse_mouse_events(evt);
        parse_keyboard_events(evt);
    }
}
