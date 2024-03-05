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

void view_sub_file_init(void)
{
    Widgets[e_subwidget_file]->size.x = UI_DROPDOWN_W;
    Widgets[e_subwidget_file]->size.y = 600;
    Widgets[e_subwidget_file]->position.x = 4.0f;
    Widgets[e_subwidget_file]->position.y = UI_CONTEXT_H - 3.0f;
    Widgets[e_subwidget_file]->backgroundColor = sfWhite;
    Widgets[e_subwidget_file]->buttonCount = 0;
    Widgets[e_subwidget_file]->visible = false;
}
