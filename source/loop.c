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

void custom_draw(widget_t *wid)
{
    sfCircleShape *c = sfCircleShape_create();

    sfCircleShape_setFillColor(c, sfBlue);
    sfCircleShape_setRadius(c, 10);
    sfCircleShape_setOrigin(c, VEC2(10, 10));
    sfCircleShape_setPosition(c, VEC2(wid->position.x + 10, wid->position.y
        + 5));
    sfRenderWindow_drawCircleShape(Win->self, c, NULL);
    sfCircleShape_destroy(c);
}

void test(void)
{
    Widgets[e_widget_toolbar]->visible = true;
    Widgets[e_widget_toolbar]->size = VEC2(1920, 20);
    Widgets[e_widget_toolbar]->hasCustomDraw = true;
    Widgets[e_widget_toolbar]->customDraw = &custom_draw;
    Widgets[e_widget_toolbar]->backgroundColor = sfWhite;
}

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
    Canvas = NULL;
    canvas_add(1280, 720, "TEST_CANVAS", sfWhite);
    Tool->canva = Canvas;
    sfRenderWindow_setMouseCursorVisible(Win->self, false);
    while (sfRenderWindow_isOpen(Win->self)) {
        events();
        sfRenderWindow_clear(Win->self, sfColor_fromRGB(237, 244, 248));
        DOIF(Tool->mousePressed, use_tool());
        for (uint i = 0; i < WIDGET_COUNT; i++)
            widget_draw(Widgets[i]);
        canvas_draw(Tool->canva);
        draw_cursor();
        sfRenderWindow_display(Win->self);
    }
}
