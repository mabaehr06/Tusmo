/*
** EPITECH PROJECT, 2024
** my_str_isupper
** File description:
** my_str_isupper
*/

#include <stdio.h>
#include "my.h"

int my_str_isupper(char const *str)
{
    int i = 0;
    int len_long = my_strlen(str);
    int check = 0;

    while (i < len_long) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            check = 1;
        } else {
            return 0;
        }
        i++;
    }
    return check;
}
