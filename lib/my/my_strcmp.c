/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int l1 = my_strlen(s1);
    int l2 = my_strlen(s2);

    if (l1 != l2)
        return 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    return 1;
}
