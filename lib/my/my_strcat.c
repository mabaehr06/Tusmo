/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *str)
{
    char *final_str;
    int dest_len = my_strlen(dest);
    int str_len = my_strlen(str);
    int i = 0;
    int j = 0;

    final_str = malloc((dest_len + str_len + 1)*sizeof(char *));
    while (dest[i] != '\0') {
        final_str[i] = dest[i];
        i++;
    }
    while (str[j] != '\0') {
        final_str[i] = str[j];
        i++;
        j++;
    }
    final_str[dest_len + str_len] = '\0';
    return final_str;
}
