/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int k = i;
    int j;

    while (str[k] != '\0') {
        j = 0;
        i = 0;
        while ('\0' != to_find[j] && to_find[j] == str[k + i]) {
            i++;
            j++;
        }
        if (to_find[j] == '\0')
            return &str[k];
        k++;
    }
    return 0;
}
