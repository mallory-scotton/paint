/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** images
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Opens an image file and creates a canvas from it.
///
/// This function takes a file path as input, opens the image file, and creates
/// a canvas with the same dimensions as the image. It then copies the image
/// pixels to the canvas. After creating the canvas, the image structure is
/// destroyed.
///
/// \param path The file path to the image.
///
///////////////////////////////////////////////////////////////////////////////
void open_image(string path)
{
    sfImage *img = sfImage_createFromFile(path);
    vec2u s;

    if (img == NULL)
        return;
    s = sfImage_getSize(img);
    canvas_add(s.x, s.y, path, sfWhite);
    my_memcpy(Canvas->pixels, sfImage_getPixelsPtr(img), (s.x * s.y * 4));
    sfImage_destroy(img);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Saves the contents of the canvas as an image file.
///
/// This function saves the contents of the current canvas as an image file at
/// the specified path. It creates an image structure from the canvas pixels
/// and then saves it to the specified file. After saving, the image structure
/// is destroyed.
///
/// \param path The file path to save the image.
///
///////////////////////////////////////////////////////////////////////////////
void save_image(string path)
{
    canvas_t *c = Tool->canva;
    sfImage *img = sfImage_createFromPixels(c->width, c->height, c->pixels);

    sfImage_saveToFile(img, path);
    sfImage_destroy(img);
}
