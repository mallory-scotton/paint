/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** buffint
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Append an integer to the content of a buffer.
///
/// This function appends an integer (value) to the content of the given
/// buffer (buffer). The parameter 'bytes_count' specifies the number of bytes
/// to consider from the integer. It iteratively extracts each byte from the
/// integer and appends it to the buffer using the 'my_buffchar' function.
///
/// \param buffer        The buffer to which the integer will be appended.
/// \param value         The integer value to append to the buffer.
/// \param bytes_count   The number of bytes to consider from the integer.
///
///////////////////////////////////////////////////////////////////////////////
void my_buffint(buffer_t *buffer, int value, uint bytes_count)
{
    for (; (bytes_count - 1) > 0; bytes_count--)
        my_buffchar(buffer, (value >> (8 * (bytes_count - 1))) & 255);
    my_buffchar(buffer, (value) & 255);
}
