/*
** EPITECH PROJECT, 2024
** my putfloat
** File description:
** my putfloat
*/

#include "../../include/project.h"

void printnb(int nb)
{
    int temp = nb;
    int size = 1;
    char *buffer = malloc((size + 1) * sizeof(char));

    if (nb < 0) {
        my_put_nbr(nb);
        return;
    }
    while (temp >= 10) {
        temp /= 10;
        size++;
    }
    buffer[size] = '\0';
    for (int i = size - 1; i >= 0; i--) {
        buffer[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    write(1, buffer, size);
    free(buffer);
}

void my_put_float(float nb)
{
    int fr_nb = nb;
    float dec_point_nb;
    float float_point_nb = (nb - fr_nb) * 1000000;

    printnb(fr_nb);
    my_putchar('.');
    if (float_point_nb < 0)
        float_point_nb = -float_point_nb;
    dec_point_nb = float_point_nb;
    if (dec_point_nb < 10) {
        my_putchar('0');
    }
    printnb(dec_point_nb);
}
