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

static void on_input(button_t *btn)
{
    if (btn->input->content->size > btn->input->maxLength) {
        btn->input->content->content = my_realloc(btn->input->content->content,
            btn->input->content->size);
        btn->input->content->size--;
        btn->input->content->content[btn->input->content->size] = '\0';
    }
    btn->text = btn->input->content->content;
    Tool->thickness = my_atoi(btn->input->content->content);
}

static void draw_text(vec2f pos, string text)
{
    sfText *t = sfText_create();

    sfText_setFont(t, OpenSans);
    sfText_setString(t, text);
    sfText_setPosition(t, pos);
    sfText_setCharacterSize(t, 18);
    sfText_setFillColor(t, COLOR_TEXT);
    sfRenderWindow_drawText(Win->self, t, NULL);
    sfText_destroy(t);
}

static void tool_option_init_button(button_t **list)
{
    button_set_input(list[0], VEC2(162, 8), e_input_num, 6);
    list[0]->text = my_strdup("15");
    my_buffstr(list[0]->input->content, "15");
    list[0]->onInput = &on_input;
}

static void draw_icon(vec2f pos, sfTexture *texture)
{
    sfSprite *icon = sfSprite_create();
    vec2u s = sfTexture_getSize(texture);
    float scalingFactorX = UI_TOOL_ICON_W / s.x;
    float scalingFactorY = UI_TOOL_ICON_H / s.y;

    sfSprite_setTexture(icon, texture, false);
    sfSprite_setScale(icon, VEC2(scalingFactorX, scalingFactorY));
    sfSprite_setPosition(icon, pos);
    sfRenderWindow_drawSprite(Win->self, icon, NULL);
    sfSprite_destroy(icon);
}

static void custom_draw(widget_t *wid)
{
    vec2f p = wid->position;

    draw_icon(Vec2.add(p, VEC2(4, 4)), Tool->toolTexture);
    draw_text(Vec2.add(p, VEC2(60, 12)), "Thickness:");
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
    Widgets[e_widget_tool_option]->hasCustomDraw = true;
    Widgets[e_widget_tool_option]->customDraw = &custom_draw;
}
