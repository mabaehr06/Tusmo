/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** debug_file
*/

#include "../../include/project.h"



static void debug_square_line(int size)
{
        debug_line_X(infos.height/size, sfBlack);
        display_text(int_to_str(size), 10, infos.height/size, sfBlack, 10, 1);
        debug_line_Y(infos.length/size, sfWhite);
        display_text(int_to_str(size), infos.length/size, 10, sfWhite, 10, 1);
        if (size-1 != 0) {
            debug_line_X((size-1)*infos.height/size, sfBlack);
            display_text(int_to_str(size), 10, (size-1)*infos.height/size, sfBlack, 10, 1);
            debug_line_Y((size-1)*infos.length/size, sfWhite);
            display_text(int_to_str(size), (size-1) * infos.length/size, 10, sfWhite, 10, 1);
        }
}


static void debug_command(void)
{
    display_text("infos.height", 10, 10, sfBlack, 10, 0);
    display_text("infos.length", 10, 25, sfWhite, 10, 0);

    for (int i = 10; i != 0; i--) {
        debug_square_line(i);
    }
}

void debug_screen(int ac, char **av)
{
    int nruter = 0;

    for (int i = 0; i != ac; i++) {
        if (my_strcmp(av[i], "-dg"))
            nruter = 1;
    }
    if (!nruter)
        return;
    debug_command();
}
