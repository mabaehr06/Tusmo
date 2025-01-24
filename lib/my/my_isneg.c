/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar(80);
    } else {
        my_putchar(78);
    }
    return 0;
}
