/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
