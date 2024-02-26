/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** rpg
*/

#ifndef PAINT_H_
    #define PAINT_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "paint/dependencies.h"
    #include "paint/types.h"
    #include "paint/utils.h"
    #include "paint/libmy.h"
    #include "paint/macros.h"
    #include "paint/global.h"
    #include "configuration.h"

void events(void);
void loop(void);
void get_rec(float thick, sfVector2f pos, sfVector2f size);

#endif /* !PAINT_H_ */
