/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** sub_new
*/

#include "paint.h"

static void close_save(button_t *btn)
{
    Widgets[e_subwidget_save]->visible = false;
    btn = btn;
}

static void on_input(button_t *btn)
{
    btn->text = btn->input->content->content;
    if (PRESSED(sfKeyEnter)) {
        Widgets[e_subwidget_file]->visible = false;
        Widgets[e_subwidget_save]->visible = false;
        save_image(btn->input->content->content);
    }
    fit_area(NULL);
}

static void view_sub_save_buttons(button_t **list)
{
    button_set_input(list[0], VEC2(4, 35), e_input_alphanum, 1024);
    my_buffstr(list[0]->input->content, "./");
    list[0]->size.x = UI_DROPDOWN_W + 92.0f;
    list[0]->text = list[0]->input->content->content;
    list[0]->onInput = &on_input;
    button_set_close(list[1], "X", VEC2(270, 0), &close_save);
}

static void custom_draw(widget_t *wid)
{
    draw_text(Vec2.add(wid->position, VEC2(4, 8)), "Path:");
}

void view_sub_save_init(void)
{
    Widgets[e_subwidget_save]->size.x = UI_DROPDOWN_W + 100.0f;
    Widgets[e_subwidget_save]->size.y = 2 * 40.0f;
    Widgets[e_subwidget_save]->cornerRadius = 0.0f;
    Widgets[e_subwidget_save]->position.x = 300.0f;
    Widgets[e_subwidget_save]->position.y = 300.0f;
    Widgets[e_subwidget_save]->backgroundColor = COLOR_BG_BTN_HOVER;
    Widgets[e_subwidget_save]->hasShadow = true;
    Widgets[e_subwidget_save]->buttonCount = 2;
    Widgets[e_subwidget_save]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_save]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_save]->buttonCount; i++) {
        Widgets[e_subwidget_save]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_save]->buttons[i]->index = i;
    }
    view_sub_save_buttons(Widgets[e_subwidget_save]->buttons);
    Widgets[e_subwidget_save]->visible = false;
    Widgets[e_subwidget_save]->hasCustomDraw = true;
    Widgets[e_subwidget_save]->customDraw = &custom_draw;
}
