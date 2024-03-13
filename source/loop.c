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

//! TEMP
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

static void need_cursor(void)
{
    if (Tool->mousePressed) {
        for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++) {
            Widgets[e_subwidget_file + i]->visible = false;
            Widgets[e_widget_context]->buttons[i]->state = e_state_active;
        }
    }
    if (!Win->cursorOnWidget && (Tool->type == e_tool_brush ||
        Tool->type == e_tool_eraser || Tool->type == e_tool_pencil)) {
        draw_cursor();
        sfRenderWindow_setMouseCursorVisible(Win->self, false);
    } else {
        sfRenderWindow_setMouseCursorVisible(Win->self, true);
    }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief The main loop of the program.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void loop(void)
{
    canvas_add(1920, 1080, "hello", sfWhite);
    view_init();
    while (sfRenderWindow_isOpen(Win->self)) {
        events();
        check_view_collisions();
        sfRenderWindow_clear(Win->self, COLOR_BG_CANVA);
        canvas_draw(Tool->canva);
        for (uint i = 0; i < WIDGET_COUNT; i++)
            widget_draw(Widgets[i]);
        DOIF(Tool->mousePressed && !Win->cursorOnWidget, use_tool());
        need_cursor();
        sfRenderWindow_display(Win->self);
    }
}
