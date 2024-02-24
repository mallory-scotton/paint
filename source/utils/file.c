/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** file
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Count the number of entries in a directory.
///
/// \param path The path of the directory.
///
/// \return The number of entries in the directory.
///
///////////////////////////////////////////////////////////////////////////////
u8 dircount(cstring path)
{
    DIR *dir = opendir(path);
    u8 count = 0;

    RETURN(dir == NULL, (u8)-1);
    for (struct dirent *info = readdir(dir); info; info = readdir(dir)) {
        if (CMP(info->d_name, ".") || CMP(info->d_name, ".."))
            continue;
        count++;
    }
    closedir(dir);
    return (count);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Retrieves the content of a directory.
///
/// \param path The path of the directory.
///
/// \return An array containing the names of the files and directories in the
///         specified path.
///
///////////////////////////////////////////////////////////////////////////////
warray dircontent(cstring path)
{
    u8 len = dircount(path);
    DIR *dir;
    warray content;
    u8 i = 0;

    RETURN(len == 0 || len == (uchar)-1, NULL);
    dir = opendir(path);
    RETURN(dir == NULL, NULL);
    content = malloc(sizeof(string) * (len + 1));
    for (struct dirent *info = readdir(dir); info; info = readdir(dir)) {
        if (CMP(info->d_name, ".") || CMP(info->d_name, ".."))
            continue;
        content[i] = my_strdup(info->d_name);
        i++;
    }
    content[len] = 0;
    closedir(dir);
    return (content);
}
