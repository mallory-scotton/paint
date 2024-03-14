/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** zoom
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Handles the use of the zoom tool.
///
/// This function is responsible for handling the use of the zoom tool. It
/// checks whether the Alt key is pressed and invokes either the zoom-out or
/// zoom-in function accordingly.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void use_zoom_tool(void)
{
    bool alt = PRESSED(sfKeyLAlt) || PRESSED(sfKeyRAlt);

    SWITCH(alt, zoom_out(NULL), zoom_in(NULL));
}
