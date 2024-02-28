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
    e_widget_canvas,
    e_widget_toolbar,
    e_widget_layers,
    WIDGET_COUNT
} widget_list_t;

typedef enum input_state_e {
    e_state_active,
    e_state_hovered,
    e_state_clicked,
    e_state_disabled,
    STATE_COUNT
} input_state_t;

typedef enum input_type_e {
    e_input_button,
    e_input_dropdown,
    e_input_text,
    e_input_checkbox,
    INPUT_COUNT
} input_type_t;

typedef struct input_s {
    input_type_t type;
    vec2f position;
    vec2f size;
    string placeholder;
    input_state_t state;
    void (*onClick)(input_t *in);
    void (*draw)(widget_t *parent, input_t *in);
    widget_t *dropdownChild;
} input_t;

typedef enum element_type_e {
    e_element_rectangle,
    e_element_circle,
    e_element_text,
    e_element_image
} element_type_t;

typedef union element_ref_u {
    sfText *text;
    sfImage *image;
    sfCircleShape *circle;
    sfRectangleShape *rectangle;
} element_ref_t;

typedef struct element_s {
    element_type_t type;
    vec2f position;
    vec2f size;
    element_ref_t self;
} element_t;

typedef struct widget_s {
    bool visible;
    vec2f position;
    vec2f size;
    sfColor backgroundColor;
    input_t **inputs;
    uint inputCount;
    element_t *elements;
    uint elementCount;
    void (*customDraw)(widget_t *wid);
    bool hasCustomDraw;
} widget_t;

extern widget_t **Widgets;

void widget_draw(widget_t *wid);
status widgets_init(void);
void widgets_destroy(void);

#endif /* !WIDGETS_H_ */
