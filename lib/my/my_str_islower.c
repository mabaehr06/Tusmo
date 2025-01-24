/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** my_str_islower
*/

#include <stdio.h>
#include "my.h"

int my_str_islower(char const *str)
{
    int i = 0;
    int len_long = my_strlen(str);
    int check = 0;

    while (i < len_long) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            check = 1;
        } else {
            return 0;
        }
        i++;
    }
    return check;
}
