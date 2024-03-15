/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** sub_file
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

static void new_it(button_t *btn)
{
    Widgets[e_subwidget_new]->visible = true;
    Widgets[e_subwidget_file]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
    btn = btn;
}

static void open_it(button_t *btn)
{
    btn = btn;
    Widgets[e_subwidget_open]->visible = true;
    Widgets[e_subwidget_file]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
}

static void save_it(button_t *btn)
{
    btn = btn;
    Widgets[e_subwidget_save]->visible = true;
    Widgets[e_subwidget_file]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
}

static void save_as(button_t *btn)
{
    btn = btn;
}

static void view_sub_file_buttons(void)
{
    button_t **list = Widgets[e_subwidget_file]->buttons;

    button_set_sub_context(list[0], "New...", VEC2(0, 0), &new_it);
    button_set_sub_context(list[1], "Open...", VEC2(0, 40), &open_it);
    button_set_sub_context(list[2], "Save", VEC2(0, 80), &save_it);
    button_set_sub_context(list[3], "Save as", VEC2(0, 120), &save_as);
    list[0]->subText = my_strdup("ALT+CTRL+N");
    list[1]->subText = my_strdup("CTRL+O");
    list[2]->subText = my_strdup("CTRL+S");
    list[3]->subText = my_strdup(">");
}

static void custom_sub_file_draw(widget_t *wid)
{
    Widgets[e_subwidget_save_as]->visible =
        wid->buttons[3]->state != e_state_active ||
        Widgets[e_subwidget_save_as]->cursorOver;
}

void view_sub_file_init(void)
{
    Widgets[e_subwidget_file]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_file]->size.y = 160;
    Widgets[e_subwidget_file]->cornerRadius = 0.0f;
    Widgets[e_subwidget_file]->position.x = 4.0f;
    Widgets[e_subwidget_file]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_file]->backgroundColor = sfWhite;
    Widgets[e_subwidget_file]->hasShadow = true;
    Widgets[e_subwidget_file]->buttonCount = 4;
    Widgets[e_subwidget_file]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_file]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_file]->buttonCount; i++) {
        Widgets[e_subwidget_file]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_file]->buttons[i]->index = i;
    }
    view_sub_file_buttons();
    Widgets[e_subwidget_file]->visible = false;
    Widgets[e_subwidget_file]->hasCustomDraw = true;
    Widgets[e_subwidget_file]->customDraw = &custom_sub_file_draw;
}
