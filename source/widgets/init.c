/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** init
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

widget_t **Widgets;

status widgets_init(void)
{
    Widgets = malloc(sizeof(widget_t *) * WIDGET_COUNT);
    RETURN(Widgets == NULL, fail);
    for (uint i = 0; i < WIDGET_COUNT; i++) {
        Widgets[i] = malloc(sizeof(widget_t));
        RETURN(Widgets[i] == NULL, fail);
        Widgets[i]->elementCount = 0;
        Widgets[i]->backgroundColor = sfRed;
        Widgets[i]->inputCount = 0;
        Widgets[i]->position = VEC2(0, 0);
        Widgets[i]->size = VEC2(0, 0);
        Widgets[i]->visible = false;
        Widgets[i]->hasCustomDraw = false;
    }
    return (success);
}

void widgets_destroy_elements(widget_t *wid)
{
    (wid) = (wid);
}

void widgets_destroy_inputs(widget_t *wid)
{
    (wid) = (wid);
}

void widgets_destroy(void)
{
    RETURN(Widgets == NULL, (void)0);
    for (uint i = 0; i < WIDGET_COUNT; i++) {
        widgets_destroy_elements(Widgets[i]);
        widgets_destroy_inputs(Widgets[i]);
        FREE(Widgets[i]);
    }
    FREE(Widgets);
}
