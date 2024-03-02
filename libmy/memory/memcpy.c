/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** memcpy
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Copy memory area
///
/// This function copies 'n' bytes from the memory area pointed to by 'src' to
/// the memory area pointed to by 'dst'. The copying stops when 'n' bytes are
/// copied or when a null terminator is encountered in the source string.
///
/// \param dst   Pointer to the destination memory area
/// \param src   Pointer to the source memory area
/// \param n     Number of bytes to copy
///
/// \return      Pointer to the destination memory area ('dst')
///////////////////////////////////////////////////////////////////////////////
void *my_memcpy(void *dst, const void *src, ulong n)
{
    string dstPtr = (string)dst;
    string srcPtr = (string)src;

    for (ulong i = 0; i < n; i++)
        dstPtr[i] = srcPtr[i];
    return (dst);
}
