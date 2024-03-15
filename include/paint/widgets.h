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
typedef struct button_s button_t;

typedef enum widget_list_e {
    e_widget_context,
    e_widget_tool_option,
    e_widget_canvas,
    e_widget_toolbar,
    e_widget_layers,
    e_widget_explorer,
    e_widget_creation,
    e_widget_brush,
    e_subwidget_file,
    e_subwidget_edit,
    e_subwidget_image,
    e_subwidget_layer,
    e_subwidget_view,
    e_subwidget_window,
    e_subwidget_help,
    e_subwidget_new,
    e_subwidget_about,
    e_subwidget_shortcut,
    e_subwidget_credit,
    e_subwidget_tuto,
    e_subwidget_virtual_key,
    e_subwidget_save_as,
    e_subwidget_open,
    e_subwidget_save,
    WIDGET_COUNT
} widget_list_t;

typedef enum state_e {
    e_state_active,
    e_state_hovered,
    e_state_clicked,
    e_state_disabled,
    STATE_COUNT
} state_t;

typedef enum input_type_e {
    e_input_alpha,
    e_input_alphanum,
    e_input_num,
    INPUT_TYPE_COUNT
} input_type_t;

typedef struct input_s {
    input_type_t type;
    buffer_t *content;
    uint maxLength;
} input_t;

typedef struct button_s {
    int index;
    vec2f size;
    vec2f pos;
    state_t state;
    sfColor backgroundColor;
    sfColor hoverBackgroundColor;
    sfColor textColor;
    sfColor iconColor;
    float cornerRadius;
    string text;
    string subText;
    sfColor subTextColor;
    uint subTextSize;
    bool asAccent;
    uint textSize;
    sfTexture *icon;
    vec2f iconSize;
    vec2f padding;
    void (*onClick)(button_t *btn);
    void (*onHover)(button_t *btn);
    void (*onLeave)(button_t *btn);
    bool asHoverEvt;
    bool asLeaveEvt;
    input_t *input;
    void (*onInput)(button_t *btn);
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
    bool cursorOver;
    float cornerRadius;
    bool hasShadow;
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
    e_assets_file1,
    e_assets_file2,
    e_assets_file3,
    e_assets_file4,
    e_assets_file5,
    e_assets_file6,
    e_assets_file7,
    e_assets_file8,
    e_assets_file9,
    e_assets_file10,
    e_assets_file11,
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
///
///////////////////////////////////////////////////////////////////////////////
void widget_draw(widget_t *wid);

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
    void (*onClick)(button_t *btn));

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes a button for the context with the specified parameters.
///
/// This function sets the initial values for a button intended for the context
/// It configures the button's background and hover background colors, text,
/// position, size, padding, and onClick function.
///
/// \param btn Pointer to the button_t structure to be initialized.
/// \param text Pointer to the texture representing the button's text.
/// \param pos Position of the button in the toolbar.
/// \param onClick Pointer to the function to be executed when the button is
///               clicked.
///
///////////////////////////////////////////////////////////////////////////////
void button_set_context(button_t *btn, string text, vec2f pos,
    void (*onClick)(button_t *btn));

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the toolbar widget and its buttons.
///
/// This function sets up the toolbar widget by defining its size, position,
/// background color, and visibility. It also creates and configures the
/// individual buttons on the toolbar.
///
///////////////////////////////////////////////////////////////////////////////
void view_toolbar_init(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the entire view.
///
/// This function initializes the context, toolbar, tool options, and layers of
/// the view. It ensures that the necessary components for the graphical user
/// interface are set up for interaction.
///
///////////////////////////////////////////////////////////////////////////////
void view_init(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse the cursor position related to the view.
///
/// \param wid The widget to check.
///
/// \return True if the cursor is over the view, false otherwise.
///
///////////////////////////////////////////////////////////////////////////////
bool cursor_over_view(widget_t *wid);

///////////////////////////////////////////////////////////////////////////////
/// \brief Checks for collisions between the cursor and view components.
///
/// This function iterates through the view components, checking for collisions
/// between the cursor and each component. It sets flags to indicate whether
/// the cursor is over a widget or a specific view element.
///
///////////////////////////////////////////////////////////////////////////////
void check_view_collisions(void);

void button_set_input(button_t *btn, vec2f pos, input_type_t type,
    uint maxLen);

void view_context_init(void);
void view_layers_init(void);
void view_tool_option_init(void);

void view_sub_file_init(void);
void view_sub_edit_init(void);
void view_sub_window_init(void);
void view_sub_image_init(void);
void view_sub_more_init(void);
void view_sub_help_init(void);
void view_sub_view_init(void);
void view_sub_layer_init(void);
void view_sub_helpcredit(void);
void view_sub_helptuto(void);
void view_sub_about_init(void);
void view_sub_shortcut_init(void);
void view_sub_save_as_init(void);
void view_sub_new_init(void);
void view_sub_open_init(void);
void view_sub_save_init(void);

void close_tuto(button_t *btn);
void tutorial(widget_t *wig);
void credit_text(widget_t *wig);

void shortcut(widget_t *wig);
void close_shortcut(button_t *btn);
void shortcut_open(button_t *btn);

void button_set_sub_context(button_t *btn, string text, vec2f pos,
    void (*onClick)(button_t *btn));
void button_set_close(button_t *btn, string Text, vec2f pos,
    void (*onClick)(button_t *btn));
void button_set_new(button_t *btn, sfTexture *icn, vec2f pos,
    void (*onClick)(button_t *btn));
void view_sub_tuto_buttons(void);

void fit_area(button_t *btn);
void zoom_out(button_t *btn);
void zoom_in(button_t *btn);

#endif /* !WIDGETS_H_ */
