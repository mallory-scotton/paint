/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** buffchar
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Append a character to the content of a buffer.
///
/// This function appends a character (c) to the content of the given buffer
/// (buffer). If the buffer's content is initially NULL, it allocates memory
/// for the content. Otherwise, it reallocates memory to accommodate the new
/// character. The size of the buffer is updated accordingly.
///
/// \param buffer  The buffer to which the character will be appended.
/// \param c       The character to append to the buffer.
///
///////////////////////////////////////////////////////////////////////////////
void my_buffchar(buffer_t *buffer, char c)
{
    if (buffer->content == NULL)
        buffer->content = malloc(sizeof(char));
    else
        buffer->content = realloc(buffer->content, (buffer->size + 1));
    buffer->content[buffer->size] = c;
    buffer->size++;
}
