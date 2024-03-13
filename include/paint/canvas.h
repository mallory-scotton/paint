/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** canvas
*/

#ifndef CANVAS_H_
    #define CANVAS_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Definition of the mathematical constant PI.
///
///////////////////////////////////////////////////////////////////////////////
    #define PI 3.14159265358979323846

///////////////////////////////////////////////////////////////////////////////
/// \brief Converts degrees to radians.
///
/// \param angle The angle in degrees.
///
/// \return The equivalent angle in radians.
///
///////////////////////////////////////////////////////////////////////////////
    #define DEG_TO_RAD(angle) (angle * PI / 180.0)

///////////////////////////////////////////////////////////////////////////////
/// \brief Converts radians to degrees.
///
/// \param angle The angle in radians.
///
/// \return The equivalent angle in degrees.
///
///////////////////////////////////////////////////////////////////////////////
    #define RAD_TO_DEG(angle) (angle * 180.0 / M_PI)

///////////////////////////////////////////////////////////////////////////////
/// \brief Converts a vector to a 2D vector.
///
/// \param vec The original vector.
///
/// \return A 2D vector with the same x and y components.
///
///////////////////////////////////////////////////////////////////////////////
    #define TV2(vec) VEC2(vec.x, vec.y)

typedef struct canvas_s canvas_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Definition of the canvas structure.
///
/// The canvas structure represents an image or drawing area in the paint
/// application.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct canvas_s {
    string name;
    string path;
    uint width;
    uint height;
    bool saved;
    vec2f position;
    vec2f scale;
    sfColor baseColor;
    sfUint8 *pixels;
    canvas_t *next;
} canvas_t;

/// Enumeration of tool types.
typedef enum tool_type_e {
    e_tool_move,
    e_tool_rectangle_select,
    e_tool_lasso,
    e_tool_eyedropper,
    e_tool_brush,
    e_tool_eraser,
    e_tool_bucket,
    e_tool_text,
    e_tool_rectangle,
    e_tool_hand,
    e_tool_zoom,
    e_tool_pencil,
    e_tool_ellipse_select,
    TOOL_COUNT
} tool_type_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Definition of the tool structure.
///
/// The tool structure represents a drawing tool in the paint application.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct tool_s {
    uint thickness;
    tool_type_t type;
    sfColor color;
    canvas_t *canva;
    bool mousePressed;
    vec2i mousePos;
    vec2i oldMousePos;
    bool wasMousePressed;
    sfColor primaryColor;
} tool_t;

/// Pointer to the active canvas list.
extern canvas_t *Canvas;

/// Pointer to the active tool.
extern tool_t *Tool;

///////////////////////////////////////////////////////////////////////////////
/// \brief Adds a new canvas to the paint application.
///
/// \param width The width of the new canvas.
/// \param height The height of the new canvas.
/// \param name The name of the new canvas.
/// \param baseColor The base color of the new canvas.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void canvas_add(uint width, uint height, string name, sfColor baseColor);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the active canvas on the window.
///
/// \param c Pointer to the canvas to be drawn.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void canvas_draw(canvas_t *c);

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the paint application's drawing tool.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void tool_init(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Handles drawing using the pencil tool.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void use_pencil_tool(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Handles erasing using the eraser tool.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void use_eraser_tool(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Set the color of a pixel
///
/// \param x The x coordinate of the pixel
/// \param y The y coordinate of the pixel
/// \param color The color to set for the pixel
///
///////////////////////////////////////////////////////////////////////////////
void setpixel(int x, int y, sfColor color);

///////////////////////////////////////////////////////////////////////////////
/// \brief Get the pixel color at x, y
///
/// \param x The x coordinate of the pixel
/// \param y The y coordiante of the pixel
///
/// \return The color of the pixel
///
///////////////////////////////////////////////////////////////////////////////
sfColor getpixel(int x, int y);

///////////////////////////////////////////////////////////////////////////////
/// \brief Handles filling using the bucket tool.
///
/// \return None.
///
///////////////////////////////////////////////////////////////////////////////
void use_bucket_tool(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the transformation rectangle on the canvas.
///
/// This function creates, initializes, renders, and then destroys the
/// transformation rectangle on the canvas. It uses the canvas's size, scale,
/// and position to determine the appropriate properties of the transformation
/// shape.
///
/// \param c A pointer to the canvas structure.
///
///////////////////////////////////////////////////////////////////////////////
void transform_draw(canvas_t *c);

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
void save_image(string path);

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
void open_image(string path);

void draw_color_picker(vec2f pos);

#endif /* !CANVAS_H_ */
