/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** buffer
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

/// Pointer to the active tool.
tool_t *Tool;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the paint application's drawing tool.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void tool_init(void)
{
    Tool = malloc(sizeof(tool_t));
    Tool->thickness = 10;
    Tool->type = e_tool_pencil;
    Tool->color = sfBlack;
    Tool->mousePos = VEC2I(0, 0);
    Tool->oldMousePos = VEC2I(0, 0);
    Tool->mousePressed = false;
    Tool->wasMousePressed = false;
    Tool->primaryColor = sfRed;
    Tool->colorPos = VEC2(0, UI_CLR_A_S);
    Tool->focus = NULL;
    Tool->toolTexture = Assets[e_assets_tool_pencil];
}
