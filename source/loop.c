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

///////////////////////////////////////////////////////////////////////////////
/// \brief The main loop of the program.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void loop(void)
{
    Canvas = NULL;
    canvas_add(1920, 1080, "TEST_CANVAS", sfWhite);
    Canvas->position = VEC2(0, 0);
    Tool->canva = Canvas;
    while (sfRenderWindow_isOpen(Win->self)) {
        events();
        sfRenderWindow_clear(Win->self, sfColor_fromRGB(237, 244, 248));
        DOIF(Tool->mousePressed, use_tool());
        for (uint i = 0; i < WIDGET_COUNT; i++)
            widget_draw(Widgets[i]);
        canvas_draw(Tool->canva);
        sfRenderWindow_display(Win->self);
    }
}
