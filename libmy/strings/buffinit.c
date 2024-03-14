/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** buffinit
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize a buffer with default values.
///
/// This function allocates memory for a new buffer and initializes its size to
/// 0. It returns a pointer to the newly created buffer.
///
/// \return Pointer to the newly initialized buffer or NULL on allocation
///         failure.
///
///////////////////////////////////////////////////////////////////////////////
buffer_t *my_buffinit(void)
{
    buffer_t *buffer = malloc(sizeof(buffer_t));

    RETURN(buffer == NULL, NULL);
    buffer->size = 0;
    return (buffer);
}
