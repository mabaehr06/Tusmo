/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 1;

    while (i * i != nb) {
        if (i * i > nb) {
            return 0;
        }
        i++;
    }
    return i;
}
