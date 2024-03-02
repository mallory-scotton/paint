/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** widgets
*/

#ifndef WIDGETS_H_
    #define WIDGETS_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "paint/dependencies.h"
    #include "paint/types.h"

typedef struct widget_s widget_t;
typedef struct input_s input_t;

typedef enum widget_list_e {
    e_widget_header,
    e_widget_tool_option,
    e_widget_canvas,
    e_widget_toolbar,
    e_widget_layers,
    e_widget_explorer,
    e_widget_creation,
    WIDGET_COUNT
} widget_list_t;

typedef enum state_e {
    e_state_active,
    e_state_hovered,
    e_state_clicked,
    e_state_disabled,
    STATE_COUNT
} state_t;

typedef struct button_s {
    vec2f size;
    vec2f pos;
    state_t state;
    sfColor backgroundColor;
    sfColor hoverBackgroundColor;
    sfColor textColor;
    sfColor iconColor;
    string content;
    sfTexture *icon;
    vec2f iconSize;
    vec2f padding;
    void (*onClick)(void);
} button_t;

typedef struct widget_s {
    bool visible;
    vec2f position;
    vec2f size;
    button_t **buttons;
    uint buttonCount;
    sfColor backgroundColor;
    void (*customDraw)(widget_t *wid);
    bool hasCustomDraw;
} widget_t;

typedef enum assets_e {
    e_assets_tool_move,
    e_assets_tool_artboard,
    e_assets_tool_rectangle_select,
    e_assets_tool_elipse_select,
    e_assets_tool_lasso,
    e_assets_tool_polygonal_lasso,
    e_assets_tool_magnetic_lasso,
    e_assets_tool_magic_wand,
    e_assets_tool_quick_selection,
    e_assets_tool_object_selection,
    e_assets_tool_eyedropper,
    e_assets_tool_brush,
    e_assets_tool_pencil,
    e_assets_tool_eraser,
    e_assets_tool_gradient,
    e_assets_tool_bucket,
    e_assets_tool_text,
    e_assets_tool_rectangle,
    e_assets_tool_ellipse,
    e_assets_tool_line,
    e_assets_tool_parametric_shape,
    e_assets_tool_custom_shape,
    e_assets_tool_hand,
    e_assets_tool_hand_rotate,
    e_assets_tool_zoom,
    e_assets_transparent,
    e_assets_zoom_plus,
    e_assets_zoom_minus,
    e_assets_virtual_key,
    e_assets_folder,
    e_assets_trash,
    e_assets_lock,
    e_assets_layers,
    ASSETS_COUNT
} assets_t;

extern sfTexture *Assets[ASSETS_COUNT];

extern widget_t **Widgets;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes assets by loading textures from files.
///
/// This function initializes assets by loading textures from files. It creates
/// sfTexture objects for each asset, storing them in the global array.
///
///////////////////////////////////////////////////////////////////////////////
void assets_init(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroys assets by freeing the allocated memory.
///
/// This function destroys assets by freeing the memory associated with the
/// sfTexture objects. It iterates over the global array and destroys each
/// texture.
///
///////////////////////////////////////////////////////////////////////////////
void assets_destroy(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws the widget.
///
/// This function draws the background of the widget, checks and sets the
/// cursor visibility, draws the buttons associated with the widget, and
/// finally calls the custom draw function if specified.
///
/// \param wid Pointer to the widget_t structure.
/// \param cursorOnWidget Pointer to the cursorOnWidget flag.
///
///////////////////////////////////////////////////////////////////////////////
void widget_draw(widget_t *wid, bool *cursorOnWidget);

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the widgets array.
///
/// This function allocates memory for the widgets array and initializes each
/// widget with default values.
///
/// \return The status of the initialization process (success or failure).
///
///////////////////////////////////////////////////////////////////////////////
status widgets_init(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroys the widgets array.
///
/// This function frees the memory allocated for the widgets array and its
/// associated buttons.
///
///////////////////////////////////////////////////////////////////////////////
void widgets_destroy(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws a button on the window.
///
/// This function creates a rectangle shape representing the button's
/// background and draws it on the render window. It also updates the button's
/// state based on mouse interaction, triggers the button's onClick function
/// if needed, and may draw an icon.
///
/// \param wid Pointer to the widget_t structure containing the button.
/// \param btn Pointer to the button_t structure.
///
///////////////////////////////////////////////////////////////////////////////
void button_draw(widget_t *wid, button_t *btn);

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes a button for the toolbar with the specified parameters.
///
/// This function sets the initial values for a button intended for the toolbar
/// It configures the button's background and hover background colors, icon,
/// position, size, padding, and onClick function.
///
/// \param btn Pointer to the button_t structure to be initialized.
/// \param icn Pointer to the texture representing the button's icon.
/// \param pos Position of the button in the toolbar.
/// \param onClick Pointer to the function to be executed when the button is
///               clicked.
///
///////////////////////////////////////////////////////////////////////////////
void button_set_toolbar(button_t *btn, sfTexture *icn, vec2f pos,
    void (*onClick)(void));

#endif /* !WIDGETS_H_ */
