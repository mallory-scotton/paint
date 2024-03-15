/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** sub_save_as
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

static void save_png(button_t *btn)
{
    if (Tool->canva->path)
        save_image(Tool->canva->path);
    else
        save_image("saved.jpg");
    btn = btn;
}

static void save_jpg(button_t *btn)
{
    if (Tool->canva->path)
        save_image(Tool->canva->path);
    else
        save_image("saved.jpg");
    btn = btn;
}

static void save_bmp(button_t *btn)
{
    if (Tool->canva->path)
        save_image(Tool->canva->path);
    else
        save_image("saved.bmp");
    btn = btn;
}

static void save_tga(button_t *btn)
{
    if (Tool->canva->path)
        save_image(Tool->canva->path);
    else
        save_image("saved.tga");
    btn = btn;
}

static void view_sub_save_as_buttons(void)
{
    button_t **list = Widgets[e_subwidget_save_as]->buttons;

    button_set_sub_context(list[0], "PNG", VEC2(0, 0), &save_png);
    button_set_sub_context(list[1], "JPG", VEC2(0, 40), &save_jpg);
    button_set_sub_context(list[2], "BMP", VEC2(0, 80), &save_bmp);
    button_set_sub_context(list[3], "TGA", VEC2(0, 120), &save_tga);
}

void view_sub_save_as_init(void)
{
    Widgets[e_subwidget_save_as]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_save_as]->size.y = 4 * 40.0f;
    Widgets[e_subwidget_save_as]->position.x = UI_DROPDOWN_W + 4.0f;
    Widgets[e_subwidget_save_as]->position.y = UI_CONTEXT_H - 3.0f + 120.0f;
    Widgets[e_subwidget_save_as]->backgroundColor = sfWhite;
    Widgets[e_subwidget_save_as]->cornerRadius = 0.0f;
    Widgets[e_subwidget_save_as]->hasShadow = true;
    Widgets[e_subwidget_save_as]->buttonCount = 4;
    Widgets[e_subwidget_save_as]->buttons = malloc(sizeof(button_t *) *
        Widgets[e_subwidget_save_as]->buttonCount);
    for (uint i = 0; i < Widgets[e_subwidget_save_as]->buttonCount; i++) {
        Widgets[e_subwidget_save_as]->buttons[i] = malloc(sizeof(button_t));
        Widgets[e_subwidget_save_as]->buttons[i]->index = i;
    }
    view_sub_save_as_buttons();
    Widgets[e_subwidget_save_as]->visible = false;
}
