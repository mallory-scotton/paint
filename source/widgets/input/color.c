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

/*
TODO: parse Tool->primaryColor to get the Y offset based on the colors
! The color could be anywhere between those numbers
! e.g: Tool->primaryColor = RGB(255, 0, 134) should be equal to ...
255,    000,    000         ==> (0 * UI_CLR_R_Q)px
255,    000,    255         ==> (1 * UI_CLR_R_Q)px
000,    000,    255         ==> (2 * UI_CLR_R_Q)px
000,    255,    255         ==> (3 * UI_CLR_R_Q)px
000,    255,    000         ==> (4 * UI_CLR_R_Q)px
255,    255,    000         ==> (5 * UI_CLR_R_Q)px
255,    000,    000         ==> (6 * UI_CLR_R_Q)px
*/
static void draw_carret(vec2f pos)
{
    sfRectangleShape *caret = sfRectangleShape_create();
    vec2f offset = {0, 0};

    sfRectangleShape_setSize(caret, VEC2(UI_CLR_R_W, 3.0f));
    sfRectangleShape_setFillColor(caret, sfWhite);
    sfRectangleShape_setPosition(caret, Vec2.add(pos, offset));
    sfRenderWindow_drawRectangleShape(Win->self, caret, NULL);
    sfRectangleShape_destroy(caret);
}

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
    draw_carret(pos);
}

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

void draw_color_picker(vec2f pos)
{
    draw_color_picker_alpha(pos);
    draw_color_picker_range(VEC2(pos.x + UI_CLR_A_S, pos.y));
    draw_rounded_rectangle(VEC2(UI_CLR_A_S + UI_CLR_R_W, 25),
        VEC2(pos.x, pos.y + UI_CLR_A_S + 10), Tool->color, 5.0f);
}
