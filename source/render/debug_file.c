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
        debug_line_Y(infos.length/size, sfWhite);
        if (size-1 != 0) {
            debug_line_X((size-1)*infos.height/size, sfBlack);
            debug_line_Y((size-1)*infos.length/size, sfWhite);
        }
}


static void debug_command(void)
{
    int contour = 10;


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