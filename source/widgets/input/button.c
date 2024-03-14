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

    sfRectangleShape_setSize(acc, VEC2(6, btn->size.y));
    sfRectangleShape_setFillColor(acc, COLOR_ACCENT);
    sfRectangleShape_setPosition(acc, VEC2(pos.x - 3, pos.y));
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
static void button_parse_state(button_t *btn, vec2f pos, widget_t *wid)
{
    vec2i mousePos;

    RETURN(btn->state == e_state_disabled, (void)0);
    if (!wid->cursorOver) {
        if (btn->state == e_state_hovered) {
            btn->state = e_state_active;
            DOIF(btn->asLeaveEvt, btn->onLeave(btn));
        }
        return;
    }
    mousePos = sfMouse_getPositionRenderWindow(Win->self);
    if (mousePos.x >= pos.x && mousePos.x < pos.x + btn->size.x &&
        mousePos.y >= pos.y && mousePos.y < pos.y + btn->size.y) {
        if (btn->state != e_state_clicked && btn->state != e_state_hovered) {
            btn->state = e_state_hovered;
            DOIF(btn->asHoverEvt, btn->onHover(btn));
        }
    } else {
        DOIF(btn->state == e_state_hovered, EQ2(btn->state, e_state_active));
    }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the text of a button.
///
/// \param btn Pointer to the button_t structure.
///
///////////////////////////////////////////////////////////////////////////////
static void button_draw_text(button_t *btn, vec2f pos)
{
    sfText *text = sfText_create();
    float pad = (btn->iconSize.x + btn->padding.x * 2) * btn->iconSize.x;

    sfText_setFont(text, OpenSans);
    sfText_setPosition(text, VEC2(pad + pos.x + btn->padding.x - 1.0f,
        pos.y + btn->padding.y));
    sfText_setString(text, btn->text);
    if (btn->state == e_state_disabled)
        btn->textColor.a = 100;
    sfText_setColor(text, btn->textColor);
    sfText_setCharacterSize(text, btn->textSize);
    sfRenderWindow_drawText(Win->self, text, NULL);
    sfText_destroy(text);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate automatically the width of a button if set by default
/// to -1.0f
///
/// \param btn The button to calculate the width
///
/// \return The width of the button base on the text and icon size
///
///////////////////////////////////////////////////////////////////////////////
static float button_calculate_width(button_t *btn)
{
    sfText *text = sfText_create();
    rectf textSize = {0, 0, 0, 0};

    if (btn->text) {
        sfText_setFont(text, OpenSans);
        sfText_setString(text, btn->text);
        sfText_setCharacterSize(text, btn->textSize);
        textSize = sfText_getLocalBounds(text);
        if (btn->icon != NULL)
            textSize.width += btn->padding.x;
    }
    sfText_destroy(text);
    return (btn->iconSize.x + textSize.width + (btn->padding.x * 2));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the subtext of a button.
///
/// This function draws the subtext of a button at the specified position.
///
/// \param btn A pointer to the button.
/// \param pos The position at which to draw the subtext.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void button_draw_subtext(button_t *btn, vec2f pos)
{
    sfText *text = sfText_create();
    rectf size;

    sfText_setFont(text, OpenSans);
    sfText_setString(text, btn->subText);
    sfText_setColor(text, btn->subTextColor);
    sfText_setCharacterSize(text, btn->subTextSize);
    size = sfText_getLocalBounds(text);
    sfText_setPosition(text, VEC2(pos.x + btn->size.x - btn->padding.x - 1.0f
        - size.width, pos.y + btn->padding.y));
    sfRenderWindow_drawText(Win->self, text, NULL);
    sfText_destroy(text);
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

    if (btn->size.x == -1.0f)
        btn->size.x = button_calculate_width(btn);
    button_parse_state(btn, pos, wid);
    if (btn->state == e_state_hovered && Tool->mousePressed) {
        btn->onClick(btn);
        Tool->mousePressed = false;
    }
    draw_rounded_rectangle(btn->size, pos, btn->state == e_state_active ||
        btn->state == e_state_disabled ? btn->backgroundColor :
        btn->hoverBackgroundColor, btn->cornerRadius);
    if (btn->state == e_state_clicked && btn->asAccent)
        button_draw_accent(btn, pos);
    DOIF(btn->icon != NULL, button_draw_icon(btn, pos));
    DOIF(btn->text != NULL, button_draw_text(btn, pos));
    DOIF(btn->subText != NULL, button_draw_subtext(btn, pos));
}
