/*
** EPITECH PROJECT, 2024
** my putfloat
** File description:
** my putfloat
*/

#include "../../include/project.h"

static void printnbexpo(int nb)
{
    int temp = nb;
    int size = 1;
    char *buffer = malloc((size + 1) * sizeof(char));

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
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
}

static void my_printexpo(int p)
{
    my_putchar('e');
    my_putchar('+');
    if (p < 10) {
        my_putchar('0');
    }
    my_put_nbr(p);
}

void print_point_nb(int mem, float dec1, float dec2)
{
    if (mem == 10 || mem == -10) {
        printnbexpo(dec2 * 1000 + 1);
    } else if ((mem < 10 && mem > 0) || (mem > -10 && mem < 0))
        printnbexpo((dec2 * 10000) + 1);
        else {
            printnbexpo(dec1);
            printnbexpo(dec2);
    }
}

int calcul_point_nb1(float float_point_nb, float dec_point_nb)
{
    if (float_point_nb < 0)
        float_point_nb = -float_point_nb;
    dec_point_nb = float_point_nb;
    return dec_point_nb;
}

int calcul_point_nb2(float float_point_nb2, float dec_point_nb2)
{
    if (float_point_nb2 < 0)
        float_point_nb2 = -float_point_nb2;
    dec_point_nb2 = float_point_nb2;
    if (dec_point_nb2 < 10) {
        my_putchar('0');
    }
    return (dec_point_nb2);
}

void my_putexpo(float nb)
{
    int fr_nb = nb;
    int mem = fr_nb;
    int p = 0;
    float dec_point_nb = 0;
    float dec_point_nb2 = 0;
    float float_point_nb = 0;
    float float_point_nb2 = (nb - fr_nb) * 10000;

    while (fr_nb >= 9 || fr_nb <= -9) {
        fr_nb = fr_nb / 10;
        p = p + 1;
    }
    printnbexpo(fr_nb);
    my_putchar('.');
    float_point_nb = nb - fr_nb * my_compute_power_rec(10, p);
    dec_point_nb = calcul_point_nb1(float_point_nb, dec_point_nb);
    dec_point_nb2 = calcul_point_nb2(float_point_nb2, dec_point_nb2);
    print_point_nb(mem, dec_point_nb, dec_point_nb2);
    my_printexpo(p);
}
