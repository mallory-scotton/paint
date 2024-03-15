/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** tool_option
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

static void dummy(button_t *btn)
{
    return (void)btn;
}

static void on_input(button_t *btn)
{
    btn->text = btn->input->content->content;
    Tool->thickness = my_atoi(btn->input->content->content);
}

static void tool_option_init_button(button_t **list)
{
    button_set_sub_context(list[0], "15", VEC2(4, 4), &dummy);
    list[0]->input = malloc(sizeof(input_t));
    list[0]->input->content = my_buffinit();
    my_buffstr(list[0]->input->content, "15");
    list[0]->onInput = &on_input;
}

void view_tool_option_init(void)
{
    Widgets[e_widget_tool_option]->size.x = WIN_WIDTH;
    Widgets[e_widget_tool_option]->size.y = UI_TOOL_H;
    Widgets[e_widget_tool_option]->position.x = 0;
    Widgets[e_widget_tool_option]->position.y = UI_CONTEXT_H;
    Widgets[e_widget_tool_option]->cornerRadius = 0.0f;
    Widgets[e_widget_tool_option]->backgroundColor = COLOR_BASE;
    Widgets[e_widget_tool_option]->buttonCount = 1;
    Widgets[e_widget_tool_option]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_widget_tool_option]->buttonCount);
    for (uint i = 0; i < Widgets[e_widget_tool_option]->buttonCount; i++) {
        Widgets[e_widget_tool_option]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_widget_tool_option]->buttons[i]->index = i;
    }
    tool_option_init_button(Widgets[e_widget_tool_option]->buttons);
    Widgets[e_widget_tool_option]->visible = true;
}
