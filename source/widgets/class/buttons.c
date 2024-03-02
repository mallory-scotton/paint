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
    btn->content = NULL;
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
