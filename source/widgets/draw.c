/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** draw
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

static void widget_background_draw(widget_t *wid)
{
    sfRectangleShape *back = sfRectangleShape_create();

    sfRectangleShape_setFillColor(back, wid->backgroundColor);
    sfRectangleShape_setSize(back, wid->size);
    sfRectangleShape_setPosition(back, wid->position);
    sfRenderWindow_drawRectangleShape(Win->self, back, NULL);
    sfRectangleShape_destroy(back);
}

void widget_draw(widget_t *wid)
{
    RETURN(!wid->visible, (void)0);
    widget_background_draw(wid);
    for (uint i = 0; i < wid->inputCount; i++)
        wid->inputs[i]->draw(wid, wid->inputs[i]);
    DOIF(wid->hasCustomDraw, wid->customDraw(wid));
}
