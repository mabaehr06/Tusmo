/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

char *my_strncat(char *dest, char const *str, int nb)
{
    int dest_len = my_strlen(dest);
    int index = 0;

    for (index = dest_len; index < (dest_len + nb); index++) {
        if (!str[index - dest_len]) {
            break;
        }
        dest[index] = str[index - dest_len];
    }
    dest[index] = '\0';
    return dest;
}
