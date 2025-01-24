/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    return str;
}
