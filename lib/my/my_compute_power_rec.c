/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    } else if (p < 0) {
        return 0;
    }
    if (p > 1) {
        nb = nb * my_compute_power_rec(nb, p - 1);
        return nb;
    }
    return 0;
}
