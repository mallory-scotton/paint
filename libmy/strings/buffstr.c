/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** buffstr
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Append a string to the content of a buffer.
///
/// This function appends a null-terminated string (str) to the content of the
/// given buffer (buffer). It iterates through each character in the string
/// and appends them to the buffer using the 'my_buffchar' function.
///
/// \param buffer  The buffer to which the string will be appended.
/// \param str     The null-terminated string to append to the buffer.
///
///////////////////////////////////////////////////////////////////////////////
void my_buffstr(buffer_t *buffer, string str)
{
    FORALL(str, my_buffchar(buffer, *str));
}
