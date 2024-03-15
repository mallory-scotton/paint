/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** event
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

sfTexture *Assets[ASSETS_COUNT];

const string textures_path[ASSETS_COUNT] = {
    ASSETS_PATH "tool_move.png",
    ASSETS_PATH "tool_artboard.png",
    ASSETS_PATH "tool_rectangle_select.png",
    ASSETS_PATH "tool_elipse_select.png",
    ASSETS_PATH "tool_lasso.png",
    ASSETS_PATH "tool_polygonal_lasso.png",
    ASSETS_PATH "tool_magnetic_lasso.png",
    ASSETS_PATH "tool_magic_wand.png",
    ASSETS_PATH "tool_quick_selection.png",
    ASSETS_PATH "tool_object_selection.png",
    ASSETS_PATH "tool_eyedropper.png",
    ASSETS_PATH "tool_brush.png",
    ASSETS_PATH "tool_pencil.png",
    ASSETS_PATH "tool_eraser.png",
    ASSETS_PATH "tool_gradient.png",
    ASSETS_PATH "tool_bucket.png",
    ASSETS_PATH "tool_text.png",
    ASSETS_PATH "tool_rectangle.png",
    ASSETS_PATH "tool_ellipse.png",
    ASSETS_PATH "tool_line.png",
    ASSETS_PATH "tool_parametric_shape.png",
    ASSETS_PATH "tool_custom_shape.png",
    ASSETS_PATH "tool_hand.png",
    ASSETS_PATH "tool_hand_rotate.png",
    ASSETS_PATH "tool_zoom.png",
    ASSETS_PATH "transparent.png",
    ASSETS_PATH "zoom_plus.png",
    ASSETS_PATH "zoom_minus.png",
    ASSETS_PATH "virtual_key.png",
    ASSETS_PATH "folder.png",
    ASSETS_PATH "trash.png",
    ASSETS_PATH "lock.png",
    ASSETS_PATH "layers.png",
    ASSETS_PATH "1640x664.png",
    ASSETS_PATH "1920x1080.png",
    ASSETS_PATH "1640x856.png",
    ASSETS_PATH "1080x1080.png",
    ASSETS_PATH "1080x1920.png",
    ASSETS_PATH "1080x1350.png",
    ASSETS_PATH "1280x720.png",
    ASSETS_PATH "800x800.png",
    ASSETS_PATH "2560x1440.png",
    ASSETS_PATH "400x400.png",
    ASSETS_PATH "1500x500.png"
};

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes assets by loading textures from files.
///
/// This function initializes assets by loading textures from files. It creates
/// sfTexture objects for each asset, storing them in the global array.
///
///////////////////////////////////////////////////////////////////////////////
void assets_init(void)
{
    for (ulong i = 0; i < ASSETS_COUNT; i++)
        Assets[i] = sfTexture_createFromFile(textures_path[i], NULL);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroys assets by freeing the allocated memory.
///
/// This function destroys assets by freeing the memory associated with the
/// sfTexture objects. It iterates over the global array and destroys each
/// texture.
///
///////////////////////////////////////////////////////////////////////////////
void assets_destroy(void)
{
    for (ulong i = 0; i < ASSETS_COUNT; i++)
        sfTexture_destroy(Assets[i]);
}
