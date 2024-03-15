/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** sub_new
*/

#include "paint.h"

static void show_it(button_t *btn)
{
    btn = btn;
}

static void close_new(button_t *btn)
{
    Widgets[e_subwidget_new]->visible = false;
    btn = btn;
}

static void on_input(button_t *btn)
{
    if (btn->input->content->size > btn->input->maxLength) {
        btn->input->content->content = my_realloc(btn->input->content->content,
            btn->input->content->size);
        btn->input->content->size--;
        btn->input->content->content[btn->input->content->size] = '\0';
    }
    btn->text = btn->input->content->content;
}

static void create_new(button_t *btn)
{
    button_t **list = Widgets[e_subwidget_new]->buttons;
    int w = my_atoi(list[1]->input->content->content);
    int h = my_atoi(list[2]->input->content->content);

    if (w > 0 && h > 0) {
        canvas_add(w, h, list[0]->input->content->content, sfWhite);
        Widgets[e_subwidget_new]->visible = false;
        fit_area(NULL);
    }
    return ((void)(btn));
}

static void init_input(button_t **list)
{
    my_buffstr(list[0]->input->content, "newCanvas");
    list[0]->text = list[0]->input->content->content;
    list[0]->onInput = &on_input;
    list[0]->size.x = 200;
    my_buffstr(list[1]->input->content, "1920");
    list[1]->text = list[1]->input->content->content;
    list[1]->onInput = &on_input;
    list[1]->size.x = 200;
    my_buffstr(list[2]->input->content, "1080");
    list[2]->text = list[2]->input->content->content;
    list[2]->onInput = &on_input;
    list[2]->size.x = 200;
    button_set_context(list[15], "Create", Vec2.add(list[2]->pos,
        VEC2(-70, 40)), &create_new);
    list[15]->backgroundColor = COLOR_ACCENT;
}

static void view_sub_new_buttons(void)
{
    button_t **list = Widgets[e_subwidget_new]->buttons;

    button_set_input(list[0], VEC2(70, 10), e_input_alphanum, 30);
    button_set_input(list[1], VEC2(70, 50), e_input_num, 7);
    button_set_input(list[2], VEC2(70, 90), e_input_num, 7);
    init_input(list);
    button_set_new(list[3], Assets[e_assets_file1], VEC2(0, 160), &show_it);
    button_set_new(list[4], Assets[e_assets_file2], VEC2(100, 160), &show_it);
    button_set_new(list[5], Assets[e_assets_file3], VEC2(200, 160), &show_it);
    button_set_new(list[6], Assets[e_assets_file4], VEC2(0, 260), &show_it);
    button_set_new(list[7], Assets[e_assets_file5], VEC2(100, 260), &show_it);
    button_set_new(list[8], Assets[e_assets_file6], VEC2(200, 260), &show_it);
    button_set_new(list[9], Assets[e_assets_file7], VEC2(0, 360), &show_it);
    button_set_new(list[10], Assets[e_assets_file8], VEC2(100, 360), &show_it);
    button_set_new(list[11], Assets[e_assets_file9], VEC2(200, 360), &show_it);
    button_set_new(list[12], Assets[e_assets_file10], VEC2(0, 460), &show_it);
    button_set_new(list[13], Assets[e_assets_file11],
        VEC2(100, 460), &show_it);
    button_set_close(list[14], "X", VEC2(270, 0), &close_new);
}

static void custom_draw(widget_t *wid)
{
    draw_text(Vec2.add(wid->position, VEC2(4, 10)), "Name:");
    draw_text(Vec2.add(wid->position, VEC2(4, 50)), "Width:");
    draw_text(Vec2.add(wid->position, VEC2(4, 90)), "Height:");
}

void view_sub_new_init(void)
{
    Widgets[e_subwidget_new]->size.x = UI_DROPDOWN_W + 100.0f;
    Widgets[e_subwidget_new]->size.y = 4 * 40.0f + 4 * 100.0f;
    Widgets[e_subwidget_new]->cornerRadius = 0.0f;
    Widgets[e_subwidget_new]->position.x = 300.0f;
    Widgets[e_subwidget_new]->position.y = 300.0f;
    Widgets[e_subwidget_new]->backgroundColor = COLOR_BG_BTN_HOVER;
    Widgets[e_subwidget_new]->hasShadow = true;
    Widgets[e_subwidget_new]->buttonCount = 16;
    Widgets[e_subwidget_new]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_new]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_new]->buttonCount; i++) {
        Widgets[e_subwidget_new]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_new]->buttons[i]->index = i;
    }
    view_sub_new_buttons();
    Widgets[e_subwidget_new]->visible = false;
    Widgets[e_subwidget_new]->hasCustomDraw = true;
    Widgets[e_subwidget_new]->customDraw = &custom_draw;
}

void button_set_new(button_t *btn, sfTexture *icn, vec2f pos,
    void (*onClick)(button_t *btn))
{
    btn->backgroundColor = sfTransparent;
    btn->hoverBackgroundColor = COLOR_BG_BTN;
    btn->text = NULL;
    btn->subText = NULL;
    btn->textColor = sfWhite;
    btn->textSize = 0;
    btn->icon = icn;
    btn->iconSize = VEC2(100.0f, 100.0f);
    btn->pos = pos;
    btn->cornerRadius = 0.0f;
    btn->size = VEC2(100.0f, 100.0f);
    btn->padding = VEC2(0.0f, 0.0f);
    btn->onClick = onClick;
    btn->iconColor = COLOR_BASE;
    btn->asHoverEvt = false;
    btn->asLeaveEvt = false;
    btn->input = NULL;
}
