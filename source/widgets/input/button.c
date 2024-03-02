/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** button
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the icon of a button.
///
/// This function creates a sprite with the button's icon texture and settings,
/// and then draws it on the render window at the specified position.
///
/// \param btn Pointer to the button_t structure.
/// \param pos Position where the icon should be drawn.
///
///////////////////////////////////////////////////////////////////////////////
static void button_draw_icon(button_t *btn, vec2f pos)
{
    sfSprite *icon = sfSprite_create();
    vec2u s = sfTexture_getSize(btn->icon);
    float scalingFactorX = btn->iconSize.x / s.x;
    float scalingFactorY = btn->iconSize.y / s.y;

    sfSprite_setTexture(icon, btn->icon, false);
    sfSprite_setColor(icon, btn->iconColor);
    sfSprite_setScale(icon, VEC2(scalingFactorX, scalingFactorY));
    sfSprite_setPosition(icon, Vec2.add(pos, btn->padding));
    sfRenderWindow_drawSprite(Win->self, icon, NULL);
    sfSprite_destroy(icon);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the accent line of a button.
///
/// This function creates a rectangle shape representing the accent line of the
/// button and draws it on the render window at the specified position.
///
/// \param btn Pointer to the button_t structure.
/// \param pos Position where the accent line should be drawn.
///
///////////////////////////////////////////////////////////////////////////////
static void button_draw_accent(button_t *btn, vec2f pos)
{
    sfRectangleShape *acc = sfRectangleShape_create();

    sfRectangleShape_setSize(acc, VEC2(4, btn->size.y));
    sfRectangleShape_setFillColor(acc, COLOR_ACCENT);
    sfRectangleShape_setPosition(acc, VEC2(pos.x - 4, pos.y));
    sfRenderWindow_drawRectangleShape(Win->self, acc, NULL);
    sfRectangleShape_destroy(acc);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Parses and updates the state of a button based on mouse interaction.
///
/// This function checks if the mouse is over the button and updates its state
/// accordingly. If the button is being hovered or clicked, it adjusts the
/// background color and may draw an accent line.
///
/// \param btn Pointer to the button_t structure.
/// \param pos Position of the button in the window.
/// \param bck Pointer to the button's background rectangle shape.
///
///////////////////////////////////////////////////////////////////////////////
static void button_parse_state(button_t *btn, vec2f pos, sfRectangleShape *bck)
{
    vec2i mousePos = sfMouse_getPositionRenderWindow(Win->self);

    if (mousePos.x >= pos.x && mousePos.x < pos.x + btn->size.x &&
        mousePos.y >= pos.y && mousePos.y < pos.y + btn->size.y) {
        if (btn->state != e_state_clicked)
            btn->state = e_state_hovered;
    } else {
        DOIF(btn->state == e_state_hovered, EQ2(btn->state, e_state_active));
    }
    if (btn->state == e_state_hovered)
        sfRectangleShape_setFillColor(bck, btn->hoverBackgroundColor);
    if (btn->state == e_state_clicked) {
        sfRectangleShape_setFillColor(bck, btn->hoverBackgroundColor);
        button_draw_accent(btn, pos);
    }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws a button on the window.
///
/// This function creates a rectangle shape representing the button's
/// background and draws it on the render window. It also updates the button's
/// state based on mouse interaction, triggers the button's onClick function
/// if needed, and may draw an icon.
///
/// \param wid Pointer to the widget_t structure containing the button.
/// \param btn Pointer to the button_t structure.
///
///////////////////////////////////////////////////////////////////////////////
void button_draw(widget_t *wid, button_t *btn)
{
    vec2f pos = Vec2.add(wid->position, btn->pos);
    sfRectangleShape *bck = sfRectangleShape_create();

    sfRectangleShape_setSize(bck, btn->size);
    sfRectangleShape_setFillColor(bck, btn->backgroundColor);
    sfRectangleShape_setPosition(bck, pos);
    button_parse_state(btn, pos, bck);
    DOIF(btn->state == e_state_hovered && Tool->mousePressed,
        btn->onClick(btn));
    sfRenderWindow_drawRectangleShape(Win->self, bck, NULL);
    DOIF(btn->icon != NULL, button_draw_icon(btn, pos));
    sfRectangleShape_destroy(bck);
}
