/*
** EPITECH PROJECT, 2024
** Template_Project
** File description:
** convert_str_into_int
*/

#include "../my/my.h"

int convert_str_into_int(char *str)
{
    int nb = 0;
    int cpt = my_strlen(str);
    int i = 1;

    while (cpt > 0) {
        nb += (str[cpt - 1] - '0') * i;
        i *= 10;
        cpt--;
    }
    return nb;
}
