/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** loop
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Calls the appropriate function based on the selected tool.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
static void use_tool(void)
{
    DOIF(Tool->type == e_tool_pencil, use_pencil_tool());
    DOIF(Tool->type == e_tool_eraser, use_eraser_tool());
    DOIF(Tool->type == e_tool_bucket, use_bucket_tool());
}

static void draw_cursor(void)
{
    sfCircleShape *c = sfCircleShape_create();
    int th = Tool->thickness * Tool->canva->scale.x;
    int r = (th / 2) == 0 ? 1 : (th / 2);

    sfCircleShape_setRadius(c, r);
    sfCircleShape_setOutlineThickness(c, 1.5f);
    sfCircleShape_setOutlineColor(c, sfColor_fromRGB(150, 150, 150));
    sfCircleShape_setFillColor(c, sfTransparent);
    sfCircleShape_setOrigin(c, VEC2(r, r));
    sfCircleShape_setPosition(c, TV2(Tool->mousePos));
    sfRenderWindow_drawCircleShape(Win->self, c, NULL);
    sfCircleShape_destroy(c);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief The main loop of the program.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void loop(void)
{
    bool cursorOnWidget = false;

    view_init();
    canvas_add(1920, 1080, "hello", sfWhite);
    while (sfRenderWindow_isOpen(Win->self)) {
        cursorOnWidget = false;
        events();
        sfRenderWindow_clear(Win->self, COLOR_BG_CANVA);
        canvas_draw(Tool->canva);
        transform_draw(Tool->canva);
        for (uint i = 0; i < WIDGET_COUNT; i++)
            widget_draw(Widgets[i], &cursorOnWidget);
        sfRenderWindow_setMouseCursorVisible(Win->self, cursorOnWidget);
        DOIF(Tool->mousePressed && !cursorOnWidget, use_tool());
        DOIF(!cursorOnWidget, draw_cursor());
        sfRenderWindow_display(Win->self);
    }
}
