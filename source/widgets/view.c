/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** view
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the entire view.
///
/// This function initializes the context, toolbar, tool options, and layers of
/// the view. It ensures that the necessary components for the graphical user
/// interface are set up for interaction.
///
///////////////////////////////////////////////////////////////////////////////
void view_init(void)
{
    view_context_init();
    view_toolbar_init();
    view_tool_option_init();
    view_layers_init();
    view_sub_file_init();
    view_sub_edit_init();
    view_sub_image_init();
    view_sub_layer_init();
    view_sub_view_init();
    view_sub_window_init();
    view_sub_more_init();
    view_sub_help_init();
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse the cursor position related to the view.
///
/// \param wid The widget to check.
///
/// \return True if the cursor is over the view, false otherwise.
///
///////////////////////////////////////////////////////////////////////////////
bool cursor_over_view(widget_t *wid)
{
    vec2i mp = sfMouse_getPositionRenderWindow(Win->self);

    if (mp.x >= wid->position.x && mp.x < wid->position.x + wid->size.x &&
        mp.y >= wid->position.y && mp.y < wid->position.y + wid->size.y) {
        wid->cursorOver = true;
        Win->cursorOnWidget = true;
        return (true);
    }
    return (false);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Checks for collisions between the cursor and view components.
///
/// This function iterates through the view components, checking for collisions
/// between the cursor and each component. It sets flags to indicate whether
/// the cursor is over a widget or a specific view element.
///
///////////////////////////////////////////////////////////////////////////////
void check_view_collisions(void)
{
    Win->cursorOnWidget = false;
    for (int i = WIDGET_COUNT - 1; i >= 0; i--) {
        if (!Win->cursorOnWidget && Widgets[i]->visible) {
            Widgets[i]->cursorOver = cursor_over_view(Widgets[i]);
            continue;
        }
        Widgets[i]->cursorOver = false;
    }
}
