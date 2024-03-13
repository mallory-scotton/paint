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

static void about_us_open(button_t *btn)
{
    Widgets[e_subwidget_about]->visible = true;
    Widgets[e_subwidget_more]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
    btn = btn;
}

static void shortcut_open(button_t *btn)
{
    Widgets[e_subwidget_shortcut]->visible = true;
    Widgets[e_subwidget_more]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
    btn = btn;
}

static void show_it(button_t *btn)
{
    btn = btn;
}

static void view_sub_more_buttons(void)
{
    button_t **list = Widgets[e_subwidget_more]->buttons;

    button_set_sub_context(list[0], "Theme", VEC2(0, 0), &show_it);
    button_set_sub_context(list[1], "Shortcuts", VEC2(0, 40), &shortcut_open);
    button_set_sub_context(list[2], "About us", VEC2(0, 80), &about_us_open);
}

void view_sub_more_init(void)
{
    Widgets[e_subwidget_more]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_more]->size.y = 3 * 40.0f;
    Widgets[e_subwidget_more]->position.x = 434.0f;
    Widgets[e_subwidget_more]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_more]->backgroundColor = sfWhite;
    Widgets[e_subwidget_more]->hasShadow = true;
    Widgets[e_subwidget_more]->buttonCount = 3;
    Widgets[e_subwidget_more]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_more]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_more]->buttonCount; i++) {
        Widgets[e_subwidget_more]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_more]->buttons[i]->index = i;
    }
    view_sub_more_buttons();
    Widgets[e_subwidget_more]->visible = false;
}

void view_sub_about_buttons(void)
{
    button_t **list = Widgets[e_subwidget_about]->buttons;

    button_set_close(list[0], "X", VEC2(770, 0), &close_about);
}

void view_sub_about_init(void)
{
    Widgets[e_subwidget_about]->size.x = 800.0f;
    Widgets[e_subwidget_about]->size.y = 400.0f;
    Widgets[e_subwidget_about]->position.x = 400.0f;
    Widgets[e_subwidget_about]->position.y = 300.0f;
    Widgets[e_subwidget_about]->backgroundColor = COLOR_BASE;
    Widgets[e_subwidget_about]->hasShadow = true;
    Widgets[e_subwidget_about]->buttonCount = 1;
    Widgets[e_subwidget_about]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_about]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_about]->buttonCount; i++) {
        Widgets[e_subwidget_about]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_tuto]->buttons[i]->index = i;
    }
    view_sub_about_buttons();
    Widgets[e_subwidget_about]->hasCustomDraw = true;
    Widgets[e_subwidget_about]->customDraw = &about;
    Widgets[e_subwidget_about]->visible = false;
}

void view_sub_shortcut_buttons(void)
{
    button_t **list = Widgets[e_subwidget_shortcut]->buttons;

    button_set_close(list[0], "X", VEC2(770, 0), &close_shortcut);
}

void view_sub_shortcut_init(void)
{
    Widgets[e_subwidget_shortcut]->size.x = 800.0f;
    Widgets[e_subwidget_shortcut]->size.y = 400.0f;
    Widgets[e_subwidget_shortcut]->position.x = 400.0f;
    Widgets[e_subwidget_shortcut]->position.y = 300.0f;
    Widgets[e_subwidget_shortcut]->backgroundColor = COLOR_BASE;
    Widgets[e_subwidget_shortcut]->hasShadow = true;
    Widgets[e_subwidget_shortcut]->buttonCount = 1;
    Widgets[e_subwidget_shortcut]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_shortcut]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_shortcut]->buttonCount; i++) {
        Widgets[e_subwidget_shortcut]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_shortcut]->buttons[i]->index = i;
    }
    view_sub_shortcut_buttons();
    Widgets[e_subwidget_shortcut]->hasCustomDraw = true;
    Widgets[e_subwidget_shortcut]->customDraw = &shortcut;
    Widgets[e_subwidget_shortcut]->visible = false;
}
