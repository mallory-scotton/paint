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

static void on_input(button_t *btn)
{
    btn->text = btn->input->content->content;
    if (PRESSED(sfKeyEnter)) {
        Widgets[e_subwidget_file]->visible = false;
        Widgets[e_subwidget_open]->visible = false;
        open_image(btn->input->content->content);
    }
    fit_area(NULL);
}

static void open_file_evt(button_t *btn)
{
    Widgets[e_subwidget_file]->visible = false;
    Widgets[e_subwidget_open]->visible = false;
    open_image(Widgets[e_subwidget_open]->buttons[0]->input->content->content);
    fit_area(NULL);
    return ((void)btn);
}

static void view_sub_open_buttons(button_t **list)
{
    button_set_input(list[0], VEC2(4, 35), e_input_alphanum, 1024);
    my_buffstr(list[0]->input->content, "./tests/images/takumi.jpg");
    list[0]->size.x = UI_DROPDOWN_W + 92.0f;
    list[0]->text = list[0]->input->content->content;
    list[0]->onInput = &on_input;
    button_set_close(list[1], "X", VEC2(270, 0), &close_open);
    button_set_context(list[2], "Open", VEC2(222, 82), &open_file_evt);
    list[2]->backgroundColor = COLOR_ACCENT;
}

static void custom_draw(widget_t *wid)
{
    draw_text(Vec2.add(wid->position, VEC2(4, 8)), "Path:");
}

void view_sub_open_init(void)
{
    Widgets[e_subwidget_open]->size.x = UI_DROPDOWN_W + 100.0f;
    Widgets[e_subwidget_open]->size.y = 3 * 40.0f;
    Widgets[e_subwidget_open]->cornerRadius = 0.0f;
    Widgets[e_subwidget_open]->position.x = 300.0f;
    Widgets[e_subwidget_open]->position.y = 300.0f;
    Widgets[e_subwidget_open]->backgroundColor = COLOR_BG_BTN_HOVER;
    Widgets[e_subwidget_open]->hasShadow = true;
    Widgets[e_subwidget_open]->buttonCount = 3;
    Widgets[e_subwidget_open]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_open]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_open]->buttonCount; i++) {
        Widgets[e_subwidget_open]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_open]->buttons[i]->index = i;
    }
    view_sub_open_buttons(Widgets[e_subwidget_open]->buttons);
    Widgets[e_subwidget_open]->visible = false;
    Widgets[e_subwidget_open]->hasCustomDraw = true;
    Widgets[e_subwidget_open]->customDraw = &custom_draw;
}
