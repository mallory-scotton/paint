/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** window
*/

///////////////////////////////////////////////////////////////////////////////
// Header
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Win global variable
///
/// \param self         References to the render window
/// \param size         2D vector representing the size of the window
/// \param isFullscreen Boolean, true if the window is in fullscreen, false
///                     otherwise.
///
///////////////////////////////////////////////////////////////////////////////
global_window_t *Win;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the window icon.
///
/// This function initializes the window icon by loading an image from the
/// specified file path (WINDOW_ICON) and setting it as the window icon. If the
/// image loading fails, the function returns without setting the icon.
///
///////////////////////////////////////////////////////////////////////////////
static void window_init_icon(void)
{
    vec2u size;
    sfImage *icon = sfImage_createFromFile(WIN_ICON);

    RETURN(icon == NULL, (void)0);
    size = sfImage_getSize(icon);
    sfRenderWindow_setIcon(Win->self, size.x, size.y,
        sfImage_getPixelsPtr(icon));
    sfImage_destroy(icon);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the window.
///
/// This function creates the main SFML window with the specified dimensions,
/// title, style, and context settings. It also initializes the window icon
/// if a valid path is provided. The window is then configured with the desired
/// framerate limit, and its position is set to the center of the screen if
/// the WINDOW_CENTERED flag is true.
///
/// \return    true if the window is successfully initialized, false otherwise
///
///////////////////////////////////////////////////////////////////////////////
status window_init(void)
{
    sfVideoMode screen = sfVideoMode_getDesktopMode();

    Win = malloc(sizeof(global_window_t));
    RETURN(Win == NULL, fail);
    Win->self = sfRenderWindow_create(WIN_MODE, WIN_TITLE, WIN_STYLE, NULL);
    RETURN(Win->self == NULL, fail);
    DOIF(WIN_ICON != NULL, window_init_icon());
    sfRenderWindow_setFramerateLimit(Win->self, WIN_FPS);
    RETURN(WIN_CENTERED == false, success);
    sfRenderWindow_setPosition(Win->self, VEC2I(MID(screen.width, WIN_WIDTH),
        MID(screen.height, WIN_HEIGHT)));
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the main window.
///
/// This function checks if the main window exists (not NULL) and destroys it
/// using sfRenderWindow_destroy. After calling this function, the window
/// pointer in the Paint structure should be set to NULL to avoid potential
/// issues with accessing a destroyed window.
///
///////////////////////////////////////////////////////////////////////////////
void window_destroy(void)
{
    RETURN(Win == NULL, (void)0);
    DOIF(Win->self != NULL, sfRenderWindow_destroy(Win->self));
    FREE(Win);
}
