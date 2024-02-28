/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** canvas
*/

#ifndef CANVAS_H_
    #define CANVAS_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "paint.h"

typedef struct canvas_s canvas_t;

typedef struct canvas_s {
    string name;
    string path;
    uint width;
    uint height;
    bool saved;
    sfUint8 *pixels;
    canvas_t *next;
} canvas_t;

extern canvas_t *Canvas;

void canvas_add(uint width, uint height, string name);
void canvas_draw(canvas_t *c, vec2f pos, vec2f scale);

#endif /* !CANVAS_H_ */
