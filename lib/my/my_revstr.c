/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

char *my_revstr(char *str)
{
    int str_len = my_strlen(str);
    char buffer = 0;

    for (int i = 0; i < (str_len / 2); i++) {
        buffer = str[i];
        str[i] = str[str_len - i - 1];
        str[str_len - i - 1] = buffer;
    }
    return str;
}
