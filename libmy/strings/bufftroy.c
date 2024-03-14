/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** bufftroy
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Deallocate memory for a buffer.
///
/// This function deallocates memory for the given buffer (buffer), including
/// its content. It checks if the buffer is initially NULL before attempting
/// to free its content and the buffer itself.
///
/// \param buffer  The buffer to deallocate.
///
///////////////////////////////////////////////////////////////////////////////
void my_bufftroy(buffer_t *buffer)
{
    RETURN(buffer == NULL, (void)0);
    DOIF(buffer->size, FREE(buffer->content));
    FREE(buffer);
}
