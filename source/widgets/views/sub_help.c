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

static void credit(button_t *btn)
{
    Widgets[e_subwidget_credit]->visible = true;
    Widgets[e_subwidget_help]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
    btn = btn;
}

static void tuto(button_t *btn)
{
    Widgets[e_subwidget_tuto]->visible = true;
    Widgets[e_subwidget_help]->visible = false;
    for (uint i = 0; i < Widgets[e_widget_context]->buttonCount; i++)
        Widgets[e_widget_context]->buttons[i]->state = e_state_active;
    btn = btn;
}

static void view_sub_help_buttons(void)
{
    button_t **list = Widgets[e_subwidget_help]->buttons;

    button_set_sub_context(list[0], "Tutorial", VEC2(0, 0), &tuto);
    button_set_sub_context(list[1], "Credits", VEC2(0, 40), &credit);
}

void view_sub_help_init(void)
{
    Widgets[e_subwidget_help]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_help]->size.y = 2 * 40.0f;
    Widgets[e_subwidget_help]->position.x = 503.0f;
    Widgets[e_subwidget_help]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_help]->backgroundColor = sfWhite;
    Widgets[e_subwidget_help]->hasShadow = true;
    Widgets[e_subwidget_help]->buttonCount = 2;
    Widgets[e_subwidget_help]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_help]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_help]->buttonCount; i++) {
        Widgets[e_subwidget_help]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_help]->buttons[i]->index = i;
    }
    view_sub_help_buttons();
    view_sub_helpcredit();
    view_sub_helptuto();
    Widgets[e_subwidget_help]->visible = false;
}

static void close_credit(button_t *btn)
{
    Widgets[e_subwidget_credit]->visible = false;
    btn = btn;
}

void close_tuto(button_t *btn)
{
    Widgets[e_subwidget_tuto]->visible = false;
    btn = btn;
}

void view_sub_credit_buttons(void)
{
    button_t **list = Widgets[e_subwidget_credit]->buttons;

    button_set_close(list[0], "X", VEC2(770, 0), &close_credit);
}

void view_sub_helpcredit(void)
{
    Widgets[e_subwidget_credit]->size.x = 800.0f;
    Widgets[e_subwidget_credit]->size.y = 400.0f;
    Widgets[e_subwidget_credit]->position.x = 400.0f;
    Widgets[e_subwidget_credit]->position.y = 300.0f;
    Widgets[e_subwidget_credit]->backgroundColor = COLOR_BASE;
    Widgets[e_subwidget_credit]->hasShadow = true;
    Widgets[e_subwidget_credit]->buttonCount = 1;
    Widgets[e_subwidget_credit]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_credit]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_credit]->buttonCount; i++) {
        Widgets[e_subwidget_credit]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_credit]->buttons[i]->index = i;
    }
    view_sub_credit_buttons();
    Widgets[e_subwidget_credit]->hasCustomDraw = true;
    Widgets[e_subwidget_credit]->customDraw = &credit_text;
    Widgets[e_subwidget_credit]->visible = false;
}

void view_sub_helptuto(void)
{
    Widgets[e_subwidget_tuto]->size.x = 800.0f;
    Widgets[e_subwidget_tuto]->size.y = 400.0f;
    Widgets[e_subwidget_tuto]->position.x = 400.0f;
    Widgets[e_subwidget_tuto]->position.y = 300.0f;
    Widgets[e_subwidget_tuto]->backgroundColor = COLOR_BASE;
    Widgets[e_subwidget_tuto]->hasShadow = true;
    Widgets[e_subwidget_tuto]->buttonCount = 1;
    Widgets[e_subwidget_tuto]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_tuto]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_tuto]->buttonCount; i++) {
        Widgets[e_subwidget_tuto]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_tuto]->buttons[i]->index = i;
    }
    view_sub_tuto_buttons();
    Widgets[e_subwidget_tuto]->hasCustomDraw = true;
    Widgets[e_subwidget_tuto]->customDraw = &tutorial;
    Widgets[e_subwidget_tuto]->visible = false;
}
