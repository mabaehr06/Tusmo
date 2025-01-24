/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

static int is_char_letter(char c)
{
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}

static int is_char_number(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    for (int i = 0; (i == 0 || str[i - 1]); i++) {
        if (i == 0 && is_char_letter(str[i])) {
            str[i] = str[i] - 'a' + 'A';
            continue;
        }
        if (!is_char_letter(str[i - 1]) && !is_char_number(str[i - 1])
            && is_char_letter(str[i])) {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    return str;
}
