/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** help_file
*/

#include "../include/project.h"

static void display_help(char **av)
{
    printf("Usage: %s\n", av[0]);
}

int help(int ac, char **av)
{
    for (int i = 0; i != ac; i++) {
        if (my_strcmp(av[i], "-h")) {
            display_help(av);
            return 1;
        }
    }
    return 0;
}