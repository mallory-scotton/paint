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
/// This function initializes the header, toolbar, tool options, and layers of
/// the view. It ensures that the necessary components for the graphical user
/// interface are set up for interaction.
///
///////////////////////////////////////////////////////////////////////////////
void view_init(void)
{
    view_header_init();
    view_toolbar_init();
    view_tool_option_init();
    view_layers_init();
}
