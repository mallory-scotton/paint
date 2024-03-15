/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** brush
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the new position based on the current color.
///
/// This function calculates the new position within the color range picker
/// based on the current color and updates the primary color and color position
/// accordingly.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void calculate_new_pos(void)
{
    sfColor color = Tool->color;
    vec2f mp;

    mp.y = 1.0 - ((float)color.r / 255.0);
    mp.x = 1.0 - ((float)color.g / 255.0);
    Tool->colorPos.y = mp.y * UI_CLR_A_S;
    Tool->colorPos.x = mp.x * UI_CLR_A_S;
    Tool->primaryColor = color;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Handles using the picker tool.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void use_picker_tool(void)
{
    canvas_t *c = Tool->canva;
    vec2f pos = VEC2(Tool->canva->position.x - ((c->width * c->scale.x) / 2),
        c->position.y - ((c->height * c->scale.y) / 2));
    vec2f mouse = Vec2.divide(Vec2.subtract(TV2(Tool->mousePos), pos),
        c->scale.x);
    int x = (int)mouse.x;
    int y = (int)mouse.y;

    Tool->color = getpixel(x, y);
    calculate_new_pos();
    return;
}
