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
        if (evt.key.code == sfKeyE)
            Tool->type = e_tool_eraser;
        if (evt.key.code == sfKeyP)
            Tool->type = e_tool_pencil;
    }
}

static void parse_scoll(sfMouseWheelScrollEvent scroll)
{
    bool ctrl = PRESSED(sfKeyLControl) || PRESSED(sfKeyRControl);
    bool alt = PRESSED(sfKeyLAlt) || PRESSED(sfKeyRAlt);
    vec2f mousePosition = TV2(scroll);
    vec2f canvasMousePosition = Vec2.subtract(mousePosition,
        Tool->canva->position);
    float zoomFactor = 1.0f + scroll.delta / 10.0f;

    if (alt) {
        Tool->canva->scale.x *= zoomFactor;
        Tool->canva->scale.y *= zoomFactor;
        Tool->canva->position = Vec2.subtract(mousePosition,
            Vec2.multiply(canvasMousePosition, zoomFactor));
    } else if (ctrl) {
        Tool->canva->position.x += scroll.delta * 10;
    } else {
        Tool->canva->position.y += scroll.delta * 10;
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
        DOIF(evt.type == sfEvtMouseWheelScrolled,
            parse_scoll(evt.mouseWheelScroll));
    }
}
