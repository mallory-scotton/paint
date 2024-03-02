/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** main
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "paint.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Prints the help message for the program.
///
/// \return Always returns 0.
///
///////////////////////////////////////////////////////////////////////////////
static int print_help(void)
{
    my_putstr("Usage :\n\t./my_paint\n\nDescription :\n\tYou can use this pr");
    my_putstr("ogram for painting or changing an image from your device to y");
    my_putstr("our liking and so on.\n");
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief The main entry point of the program.
///
/// \param argc The number of command-line arguments.
/// \param argv An array of command-line argument strings.
///
/// \return Returns 0 upon successful execution.
///
///////////////////////////////////////////////////////////////////////////////
int main(int argc, warray argv)
{
    RETURN(argc == 2 && my_strcmp(argv[1], "--help") == 0, print_help());
    window_init();
    time_init();
    widgets_init();
    tool_init();
    assets_init();
    loop();
    widgets_destroy();
    window_destroy();
    time_destroy();
    assets_destroy();
    return (0);
}
