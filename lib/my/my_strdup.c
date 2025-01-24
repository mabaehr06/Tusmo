/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** My strdup file
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int src_len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (src_len + 1));

    my_strcpy(dest, src);
    dest[src_len] = '\0';
    return dest;
}
