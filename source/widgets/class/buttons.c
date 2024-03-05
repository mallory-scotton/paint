/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** buttons
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes a button for the toolbar with the specified parameters.
///
/// This function sets the initial values for a button intended for the toolbar
/// It configures the button's background and hover background colors, icon,
/// position, size, padding, and onClick function.
///
/// \param btn Pointer to the button_t structure to be initialized.
/// \param icn Pointer to the texture representing the button's icon.
/// \param pos Position of the button in the toolbar.
/// \param onClick Pointer to the function to be executed when the button is
///               clicked.
///
///////////////////////////////////////////////////////////////////////////////
void button_set_toolbar(button_t *btn, sfTexture *icn, vec2f pos,
    void (*onClick)(button_t *btn))
{
    btn->backgroundColor = sfTransparent;
    btn->hoverBackgroundColor = COLOR_BG_BTN_HOVER;
    btn->text = NULL;
    btn->textColor = sfWhite;
    btn->textSize = 0;
    btn->icon = icn;
    btn->iconSize = VEC2(UI_TOOL_ICON_W, UI_TOOL_ICON_H);
    btn->pos = pos;
    btn->size = VEC2(UI_TOOL_W, UI_TOOL_H);
    btn->padding = VEC2(MID(UI_TOOL_W, UI_TOOL_ICON_W), MID(UI_TOOL_H,
        UI_TOOL_ICON_H));
    btn->onClick = onClick;
    btn->textColor = sfTransparent;
    btn->iconColor = COLOR_TEXT;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes a button for the context with the specified parameters.
///
/// This function sets the initial values for a button intended for the context
/// It configures the button's background and hover background colors, text,
/// position, size, padding, and onClick function.
///
/// \param btn Pointer to the button_t structure to be initialized.
/// \param text Pointer to the texture representing the button's text.
/// \param pos Position of the button in the toolbar.
/// \param onClick Pointer to the function to be executed when the button is
///               clicked.
///
///////////////////////////////////////////////////////////////////////////////
void button_set_context(button_t *btn, string text, vec2f pos,
    void (*onClick)(button_t *btn))
{
    btn->backgroundColor = sfTransparent;
    btn->hoverBackgroundColor = COLOR_BG_INPUT;
    btn->text = my_strdup(text);
    btn->textColor = COLOR_TEXT;
    btn->textSize = 18;
    btn->icon = NULL;
    btn->state = e_state_active;
    btn->padding = VEC2(12.0f, 4.0f);
    btn->pos = pos;
    btn->onClick = onClick;
    btn->iconSize = VEC2(0, 0);
    btn->size = VEC2(-1.0f, 30.0f);
}
