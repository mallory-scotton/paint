/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** color
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

static bool has_focus;

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws a range of color quads representing different color shades.
///
/// This function draws a range of color quads representing different color
/// shades from the specified start color to the specified end color.
///
/// \param pos The position of the top-left corner of the color range picker.
/// \param start The start color of the color range.
/// \param end The end color of the color range.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void draw_color_quads(vec2f pos, sfColor start, sfColor end)
{
    sfVertexArray *arr = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(arr, sfQuads);
    APPEND(arr, VERTEX(pos, start));
    APPEND(arr, VERTEX(VEC2(pos.x + UI_CLR_R_W, pos.y), start));
    APPEND(arr, VERTEX(VEC2(pos.x + UI_CLR_R_W, pos.y + UI_CLR_R_Q), end));
    APPEND(arr, VERTEX(VEC2(pos.x, pos.y + UI_CLR_R_Q), end));
    sfRenderWindow_drawVertexArray(Win->self, arr, NULL);
    sfVertexArray_destroy(arr);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Converts a color to a Y offset within the color range picker.
///
/// This function calculates the Y offset within the color range picker
/// corresponding to the given color.
///
/// \param c The color to convert to a Y offset.
///
/// \return The Y offset within the color range picker.
///
///////////////////////////////////////////////////////////////////////////////
static float color_to_offset(sfColor c)
{
    if (c.r == 255 && c.g == 0 && (c.b < 255 || c.b == 255))
        return (((float)(c.b) / 255) * UI_CLR_R_Q);
    if ((c.r < 255 || c.r == 255) && c.g == 0 && c.b == 255)
        return (((float)(255 - c.r) / 255) * UI_CLR_R_Q + UI_CLR_R_Q);
    if (c.r == 0 && (c.g < 255 || c.g == 255) && c.b == 255)
        return (((float)(c.g) / 255) * UI_CLR_R_Q + UI_CLR_R_Q * 2);
    if (c.r == 0 && c.g == 255 && (c.b < 255 || c.b == 255))
        return (((float)(255 - c.b) / 255) * UI_CLR_R_Q + UI_CLR_R_Q * 3);
    if ((c.r < 255 || c.r == 255) && c.g == 255 && c.b == 0)
        return (((float)(c.r) / 255) * UI_CLR_R_Q + UI_CLR_R_Q * 4);
    return (((float)(255 - c.g) / 255) * UI_CLR_R_Q + UI_CLR_R_Q * 5);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Converts a Y offset within the color range picker to a color.
///
/// This function calculates the color corresponding to the given Y offset
/// within the color range picker.
///
/// \param offset The Y offset within the color range picker.
///
/// \return The color corresponding to the Y offset.
///
///////////////////////////////////////////////////////////////////////////////
static sfColor offset_to_color(float offset)
{
    int quad = (int)offset / UI_CLR_R_Q;
    sfColor color = RGB(0, 0, 0);

    offset -= (quad * UI_CLR_R_Q);
    DOIF(quad == 0 || quad == 5, color.r = 255);
    DOIF(quad == 3 || quad == 4, color.g = 255);
    DOIF(quad == 1 || quad == 2, color.b = 255);
    DOIF(quad == 0, color.b = (offset * 255 / UI_CLR_R_Q));
    DOIF(quad == 1, color.r = 255 - (offset * 255 / UI_CLR_R_Q));
    DOIF(quad == 2, color.g = (offset * 255 / UI_CLR_R_Q));
    DOIF(quad == 3, color.b = 255 - (offset * 255 / UI_CLR_R_Q));
    DOIF(quad == 4, color.r = (offset * 255 / UI_CLR_R_Q));
    DOIF(quad == 5, color.g = 255 - (offset * 255 / UI_CLR_R_Q));
    return (color);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws a caret indicating the current selected color in the color
/// range picker.
///
/// This function draws a caret indicating the current selected color in the
/// color range picker at the specified position.
///
/// \param pos The position of the caret in the color range picker.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void draw_caret(vec2f pos)
{
    sfRectangleShape *caret = sfRectangleShape_create();
    float offsetY = color_to_offset(Tool->primaryColor);

    sfRectangleShape_setSize(caret, VEC2(UI_CLR_R_W, 2.0f));
    sfRectangleShape_setFillColor(caret, sfWhite);
    sfRectangleShape_setPosition(caret, Vec2.add(pos, VEC2(0.0f, offsetY)));
    sfRenderWindow_drawRectangleShape(Win->self, caret, NULL);
    sfRectangleShape_destroy(caret);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the color range picker.
///
/// This function draws the color range picker at the specified position.
///
/// \param pos The position of the top-left corner of the color range picker.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void draw_color_picker_range(vec2f pos)
{
    draw_color_quads(pos, RGB(255, 0, 0), RGB(255, 0, 255));
    draw_color_quads(VEC2(pos.x, pos.y + UI_CLR_R_Q),
        RGB(255, 0, 255), RGB(0, 0, 255));
    draw_color_quads(VEC2(pos.x, pos.y + UI_CLR_R_Q * 2),
        RGB(0, 0, 255), RGB(0, 255, 255));
    draw_color_quads(VEC2(pos.x, pos.y + UI_CLR_R_Q * 3),
        RGB(0, 255, 255), RGB(0, 255, 0));
    draw_color_quads(VEC2(pos.x, pos.y + UI_CLR_R_Q * 4),
        RGB(0, 255, 0), RGB(255, 255, 0));
    draw_color_quads(VEC2(pos.x, pos.y + UI_CLR_R_Q * 5),
        RGB(255, 255, 0), RGB(255, 0, 0));
    draw_caret(pos);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws color samples representing different colors.
///
/// This function draws color samples representing different colors at the
/// specified position.
///
/// \param pos The position of the color samples.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void draw_color_samples(vec2f pos)
{
    draw_rounded_rectangle(VEC2(25.0f, 25.0f), pos, RGB(255, 255, 255), 5);
    draw_rounded_rectangle(VEC2(25.0f, 25.0f), VEC2(pos.x + 30.0f, pos.y),
        RGB(0, 0, 0), 5.0f);
    draw_rounded_rectangle(VEC2(25.0f, 25.0f), VEC2(pos.x + 60.0f, pos.y),
        RGB(255, 0, 0), 5.0f);
    draw_rounded_rectangle(VEC2(25.0f, 25.0f), VEC2(pos.x + 90.0f, pos.y),
        RGB(0, 255, 0), 5.0f);
    draw_rounded_rectangle(VEC2(25.0f, 25.0f), VEC2(pos.x + 120.0f, pos.y),
        RGB(0, 0, 255), 5.0f);
    draw_rounded_rectangle(VEC2(25.0f, 25.0f), VEC2(pos.x + 150.0f, pos.y),
        RGB(255, 0, 255), 5.0f);
    draw_rounded_rectangle(VEC2(25.0f, 25.0f), VEC2(pos.x + 180.0f, pos.y),
        RGB(0, 255, 255), 5.0f);
    draw_rounded_rectangle(VEC2(25.0f, 25.0f), VEC2(pos.x + 210.0f, pos.y),
        RGB(255, 255, 0), 5.0f);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the alpha slider of the color picker.
///
/// This function draws the alpha slider of the color picker at the specified
/// position.
///
/// \param pos The position of the top-left corner of the alpha slider.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void draw_color_picker_alpha(vec2f pos)
{
    sfVertexArray *arr = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(arr, sfQuads);
    APPEND(arr, VERTEX(pos, sfWhite));
    APPEND(arr, VERTEX(VEC2(pos.x + UI_CLR_A_S, pos.y), Tool->primaryColor));
    APPEND(arr, VERTEX(VEC2(pos.x + UI_CLR_A_S, pos.y + UI_CLR_A_S), sfBlack));
    APPEND(arr, VERTEX(VEC2(pos.x, pos.y + UI_CLR_A_S), sfBlack));
    sfRenderWindow_drawVertexArray(Win->self, arr, NULL);
    sfVertexArray_destroy(arr);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws a color caret at a specified position.
///
/// This function draws a color caret at the specified position on the canvas.
///
/// \param pos The position of the caret on the canvas.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void draw_caret_color(vec2f pos)
{
    sfCircleShape *caret = sfCircleShape_create();

    sfCircleShape_setRadius(caret, 8.0f);
    sfCircleShape_setFillColor(caret, Tool->color);
    sfCircleShape_setOutlineThickness(caret, 1.5f);
    sfCircleShape_setOutlineColor(caret, RGB(150, 150, 150));
    sfCircleShape_setOrigin(caret, VEC2(8.0f, 8.0f));
    sfCircleShape_setPosition(caret, Vec2.add(pos, Tool->colorPos));
    sfRenderWindow_drawCircleShape(Win->self, caret, NULL);
    sfCircleShape_destroy(caret);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Converts a position on the canvas to a color.
///
/// This function converts a position on the canvas to a color, considering
/// the primary color and the position of the mouse pointer.
///
/// \param pos The position on the canvas where the color is sampled.
/// \param mousePos The current position of the mouse pointer.
///
/// \return The color sampled from the canvas.
///
///////////////////////////////////////////////////////////////////////////////
static sfColor pos_to_color(vec2f pos, vec2f mousePos)
{
    vec2f mp = Vec2.subtract(mousePos, pos);
    sfColor color = RGB(0, 0, 0);
    sfColor c = Tool->primaryColor;

    mp.x = CLAMP(mp.x, 0, UI_CLR_A_S) / UI_CLR_A_S;
    mp.y = CLAMP(mp.y, 0, UI_CLR_A_S) / UI_CLR_A_S;
    color.r = (1 - mp.y) * ((1 - mp.x) * 255 + mp.x * c.r);
    color.g = (1 - mp.y) * ((1 - mp.x) * 255 + mp.x * c.g);
    color.b = (1 - mp.y) * ((1 - mp.x) * 255 + mp.x * c.b);
    Tool->colorPos = Vec2.multiply(mp, (float)UI_CLR_A_S);
    return (color);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the entire color picker interface.
///
/// This function draws the entire color picker interface at the specified
/// position.
///
/// \param pos The position of the top-left corner of the color picker
/// interface.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void draw_color_picker(vec2f pos)
{
    DOIF(!Tool->mousePressed, has_focus = false);
    DOIF(has_focus, Win->cursorOnWidget = true);
    draw_color_picker_alpha(pos);
    draw_color_picker_range(VEC2(pos.x + UI_CLR_A_S, pos.y));
    draw_rounded_rectangle(VEC2(UI_CLR_A_S + UI_CLR_R_W, 25),
        VEC2(pos.x, pos.y + UI_CLR_A_S + 10), RGBA(Tool->color.r,
        Tool->color.g, Tool->color.b, 255), 5.0f);
    draw_color_samples(VEC2(pos.x, pos.y + UI_CLR_A_S + 45.0f));
    if (Tool->mousePressed && mouse_in(VEC2(pos.x + UI_CLR_A_S, pos.y),
        VEC2(UI_CLR_R_W, UI_CLR_A_S)) && !has_focus) {
        Tool->primaryColor = offset_to_color(Tool->mousePos.y - pos.y);
        Tool->color = pos_to_color(pos, Vec2.add(Tool->colorPos, pos));
    }
    if (Tool->mousePressed && mouse_in(pos, VEC2(UI_CLR_A_S, UI_CLR_A_S)))
        has_focus = true;
    DOIF(has_focus, Tool->color = pos_to_color(pos, TV2(Tool->mousePos)));
    draw_caret_color(pos);
}
