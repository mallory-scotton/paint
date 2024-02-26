/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-mallory.scotton
** File description:
** main
*/
#include "paint.h"

int print_help(void)
{
    my_putstr("Usage :\n\t./my_paint\n\nDescription :\n\tYou can use this pr");
    my_putstr("ogram for painting or changing an image from your device to y");
    my_putstr("our liking and so on.\n");
    return 0;
}

int main(int argc, warray argv)
{
    if (argc == 2)
        RETURN(my_strcmp(argv[1], "--help") == 0, print_help());
    window_init();
    time_init();
    window_destroy();
    time_destroy();
    return 0;
}
