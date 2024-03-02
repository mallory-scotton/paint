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

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the widgets array.
///
/// This function allocates memory for the widgets array and initializes each
/// widget with default values.
///
/// \return The status of the initialization process (success or failure).
///
///////////////////////////////////////////////////////////////////////////////
status widgets_init(void)
{
    Widgets = malloc(sizeof(widget_t *) * WIDGET_COUNT);
    RETURN(Widgets == NULL, fail);
    for (uint i = 0; i < WIDGET_COUNT; i++) {
        Widgets[i] = malloc(sizeof(widget_t));
        RETURN(Widgets[i] == NULL, fail);
        Widgets[i]->backgroundColor = sfTransparent;
        Widgets[i]->buttonCount = 0;
        Widgets[i]->buttons = NULL;
        Widgets[i]->position = VEC2(0, 0);
        Widgets[i]->size = VEC2(0, 0);
        Widgets[i]->visible = false;
        Widgets[i]->hasCustomDraw = false;
    }
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroys the widgets array.
///
/// This function frees the memory allocated for the widgets array and its
/// associated buttons.
///
///////////////////////////////////////////////////////////////////////////////
void widgets_destroy(void)
{
    RETURN(Widgets == NULL, (void)0);
    for (uint i = 0; i < WIDGET_COUNT; i++) {
        for (uint k = 0; k < Widgets[i]->buttonCount; k++)
            FREE(Widgets[i]->buttons[k]);
        FREE(Widgets[i]);
    }
    FREE(Widgets);
}
