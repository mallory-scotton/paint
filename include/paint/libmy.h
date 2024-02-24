/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** libmy
*/

#ifndef LIBMY_H_
    #define LIBMY_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "paint/types.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the length of a null-terminated string.
///
/// \param str  Pointer to the null-terminated string.
///
/// \return The length of the string (excluding the null terminator)
///
///////////////////////////////////////////////////////////////////////////////
ulong my_strlen(cstring str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Duplicate a string
///
/// \param str   The input string to duplicate
///
/// \return      A pointer to the duplicated string, or NULL if memory
///              allocation fails
///
///////////////////////////////////////////////////////////////////////////////
string my_strdup(cstring str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the length of a null-terminated array of strings
///
/// \param wa   Pointer to the null-terminated array of strings
///
/// \return     The length of the array (number of strings)
///
///////////////////////////////////////////////////////////////////////////////
ulong my_walen(warray wa);

///////////////////////////////////////////////////////////////////////////////
/// \brief Deallocate memory for a null-terminated array of strings
///
/// \param wa  Pointer to the null-terminated array of strings
///
///////////////////////////////////////////////////////////////////////////////
void my_watroy(warray wa);

///////////////////////////////////////////////////////////////////////////////
/// \brief Count the number of words in the string
///
/// \param str  Pointer to the null-derminated string
///
/// \return Return the number of words
///
///////////////////////////////////////////////////////////////////////////////
ulong my_wcount(cstring str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a word array
///
/// \param str  Pointer to the null-derminated string
///
/// \return Array of words
///
///////////////////////////////////////////////////////////////////////////////
warray my_stowa(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Print a null-terminated string to the standard output.
///
/// \param str  Pointer to the null-terminated string to be printed.
///
///////////////////////////////////////////////////////////////////////////////
void my_putstr(cstring str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Print a null-terminated string to the standard error output.
///
/// \param str  Pointer to the null-terminated string to be printed.
///
///////////////////////////////////////////////////////////////////////////////
void my_puterr(cstring str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Print a single character to the standard output.
///
/// \param ch   The character to be printed.
///
///////////////////////////////////////////////////////////////////////////////
void my_putchar(int ch);

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
void *my_memcpy(void *dst, const void *src, ulong n);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a character is a whitespace character (tab, newline,
/// vertical tab, form feed, carriage return, or space).
///
/// \param c    The character to check
///
/// \return true if the character is a whitespace character, false otherwise.
///
///////////////////////////////////////////////////////////////////////////////
bool my_isspace(int c);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a character is a digit (0-9).
///
/// \param c     The character to check.
///
/// \return      true if the character is a digit, false otherwise.
///
///////////////////////////////////////////////////////////////////////////////
bool my_isdigit(int c);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a character is an alphabetic character (A-Z or a-z).
///
/// \param c     The character to check.
///
/// \return      true if the character is an alphabetic character, false
///              otherwise.
///
///////////////////////////////////////////////////////////////////////////////
bool my_isalpha(int c);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a character is an alphanumeric character (letter or digit).
///
/// \param c     The character to check.
///
/// \return      1 if the character is alphanumeric, 0 otherwise.
///
///////////////////////////////////////////////////////////////////////////////
bool my_isalnum(int c);

///////////////////////////////////////////////////////////////////////////////
/// \brief Safe free avoiding freeing NULL
///
/// \param ptr The pointer
///
///////////////////////////////////////////////////////////////////////////////
void my_free(void **ptr);

///////////////////////////////////////////////////////////////////////////////
/// \brief Count the occurrences of a specified character in a null-terminated
///        string.
///
/// \param str  Pointer to the null-terminated string.
/// \param ch   The character to count in the string.
///
/// \return     The number of occurrences of the specified character in the
///             string.
///
///////////////////////////////////////////////////////////////////////////////
ulong my_countchar(cstring str, char ch);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert uppercased character into lowercased character
///
/// \param c    The character to convert
///
/// \return The converted character
///
///////////////////////////////////////////////////////////////////////////////
int my_tolower(int c);

///////////////////////////////////////////////////////////////////////////////
/// \brief Reallocate memory for a block with a new size and copy the
/// existing data.
///
/// \param ptr   Pointer to the current memory block to be reallocated.
/// \param size  New size of the memory block in bytes.
///
/// \return      Pointer to the reallocated and copied memory block.
///
///////////////////////////////////////////////////////////////////////////////
void *my_realloc(void *ptr, ulong size);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string represents a valid integer
///
/// \param str  The input string to check for integer representation
///
/// \return Returns true if 'str' represents a valid integer, otherwise
/// false
///
///////////////////////////////////////////////////////////////////////////////
bool my_isint(cstring str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string represents a valid floating-point number
///
/// \param str  The input string to check for floating-point representation
///
/// \return    Returns true if 'str' represents a valid floating-point number,
///            otherwise false
///
///////////////////////////////////////////////////////////////////////////////
bool my_isfloat(cstring str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string represents a valid boolean value
///
/// \param str  The input string to check for boolean representation
///
/// \return    Returns true if 'str' represents a valid boolean value,
///            otherwise false
///
///////////////////////////////////////////////////////////////////////////////
bool my_isbool(cstring str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to an integer
///
/// \param str  The input string to convert to an integer
///
/// \return    Returns the integer value corresponding to 'str'
///
///////////////////////////////////////////////////////////////////////////////
int my_atoi(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a floating-point number
///
/// \param str  The input string to convert to a floating-point number
///
/// \return    Returns the floating-point value corresponding to 'str'
///
///////////////////////////////////////////////////////////////////////////////
double my_atof(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a boolean value
///
/// \param str  The input string to convert to a boolean value
///
/// \return    Returns the boolean value corresponding to 'str',
///            or false if the conversion is not possible
///////////////////////////////////////////////////////////////////////////////
bool my_atob(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Compare two strings.
///
/// \param s1    The first string to compare.
/// \param s2    The second string to compare.
///
/// \return An integer less than, equal to, or greater than zero if s1
/// is found, respectively, to be less than, to match, or be greater than s2.
///
///////////////////////////////////////////////////////////////////////////////
int my_strcmp(cstring s1, cstring s2);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert all uppercase letters in a string to lowercase
///
/// \param str      The string to convert.
///
/// \return A pointer to the modified string
///
///////////////////////////////////////////////////////////////////////////////
string my_strlwr(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a long integer
///
/// \param s     The string to convert
/// \param ptr   A pointer to a pointer to char, which will be updated to point
///              to the first non-converted character
///
/// \return      The converted long integer value
///
///////////////////////////////////////////////////////////////////////////////
int my_strtol(char *s, char **ptr);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a word array using a separator
///
/// \param str  Pointer to the null-derminated string
/// \param str  The separator used
///
/// \return Array of words
///
///////////////////////////////////////////////////////////////////////////////
warray my_strsplit(string str, char separator);

///////////////////////////////////////////////////////////////////////////////
/// \brief Locate the first occurrence of any character in a set.
///
/// \param s        Pointer to the null-terminated string to search.
/// \param accept   Pointer to the null-terminated set of characters to match.
///
/// \return A pointer to the first matching character in the string or NULL.
///
///////////////////////////////////////////////////////////////////////////////
string my_strpbrk(cstring s, cstring accept);

///////////////////////////////////////////////////////////////////////////////
/// \brief Locate the first occurrence of a character in a string.
///
/// \param p   Pointer to the null-terminated string to search.
/// \param ch  The character to search for.
///
/// \return A pointer to the first matching character in the string or NULL.
///
///////////////////////////////////////////////////////////////////////////////
string my_strchr(cstring p, int ch);

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the length of the initial segment of a string consisting
///        of only characters from another string.
///
/// \param s1  Pointer to the null-terminated string to check.
/// \param s2  Pointer to the null-terminated string containing characters to
///            match against.
///
/// \return The length of the initial segment of s1 consisting of only
///         characters from s2.
///
///////////////////////////////////////////////////////////////////////////////
ulong my_strspn(cstring s1, cstring s2);

///////////////////////////////////////////////////////////////////////////////
/// \brief Extract tokens from a string.
///
/// \param s          String to tokenize (NULL for subsequent calls).
/// \param delim      Delimiter characters.
/// \param save_ptr   Pointer to a string to maintain state across calls.
///
/// \return A pointer to the next token in the string, or NULL if no more
///         tokens are found.
///
///////////////////////////////////////////////////////////////////////////////
string my_strtok_r(string s, cstring delim, string *save_ptr);

///////////////////////////////////////////////////////////////////////////////
/// \brief Extract tokens from a string.
///
/// \param str    String to tokenize (NULL for subsequent calls).
/// \param delim  Delimiter characters.
///
/// \return A pointer to the next token in the string, or NULL if no more
///         tokens are found.
///
///////////////////////////////////////////////////////////////////////////////
string my_strtok(string str, cstring delim);

///////////////////////////////////////////////////////////////////////////////
/// \brief Concatenate three null-terminated strings and return the result.
///
/// \param s1  Pointer to the first null-terminated string.
/// \param s2  Pointer to the second null-terminated string.
/// \param s3  Pointer to the third null-terminated string.
///
/// \return    A dynamically allocated string containing the concatenated
///            result, or NULL on allocation failure.
///
///////////////////////////////////////////////////////////////////////////////
string my_strdcat(cstring s1, cstring s2, cstring s3);

#endif /* !LIBMY_H_ */
