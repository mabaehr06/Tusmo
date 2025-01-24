/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    return str;
}
