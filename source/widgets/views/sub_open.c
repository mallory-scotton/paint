/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** sub_new
*/

#include "paint.h"

static void close_open(button_t *btn)
{
    Widgets[e_subwidget_open]->visible = false;
    btn = btn;
}

static void dummy(button_t *btn)
{
    return (void)btn;
}

static void on_input(button_t *btn)
{
    btn->text = btn->input->content->content;
    if (PRESSED(sfKeyEnter)) {
        Widgets[e_subwidget_open]->visible = false;
        open_image(btn->input->content->content);
    }
    fit_area(NULL);
}

static void view_sub_open_buttons(button_t **list)
{
    button_set_sub_context(list[0], "path file", VEC2(2, 20), &dummy);
    list[0]->input = malloc(sizeof(input_t));
    list[0]->input->type = e_input_alphanum;
    list[0]->input->content = my_buffinit();
    my_buffstr(list[0]->input->content, "path file");
    list[0]->onInput = &on_input;
    button_set_close(list[1], "X", VEC2(270, 0), &close_open);
}

void view_sub_open_init(void)
{
    Widgets[e_subwidget_open]->size.x = UI_DROPDOWN_W + 100.0f;
    Widgets[e_subwidget_open]->size.y = 2 * 40.0f;
    Widgets[e_subwidget_open]->cornerRadius = 0.0f;
    Widgets[e_subwidget_open]->position.x = 300.0f;
    Widgets[e_subwidget_open]->position.y = 300.0f;
    Widgets[e_subwidget_open]->backgroundColor = COLOR_BG_BTN_HOVER;
    Widgets[e_subwidget_open]->hasShadow = true;
    Widgets[e_subwidget_open]->buttonCount = 2;
    Widgets[e_subwidget_open]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_open]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_open]->buttonCount; i++) {
        Widgets[e_subwidget_open]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_open]->buttons[i]->index = i;
    }
    view_sub_open_buttons(Widgets[e_subwidget_open]->buttons);
    Widgets[e_subwidget_open]->visible = false;
}
