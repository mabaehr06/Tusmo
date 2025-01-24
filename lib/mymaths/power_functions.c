/*
** EPITECH PROJECT, 2025
** Project_template
** File description:
** exponential
*/

#include "mymaths.h"

int my_pow(int number, int power)
{
    int initial = number;

    for (int i = 1; i < power; i++) {
        number *= initial;
    }
    return number;
}

double my_fpow(double number, double power)
{
    double initial = number;

    for (int i = 1; i < power; i++) {
        number *= initial;
    }
    return number;
}

double my_dexp(double power)
{
    double x = 1;

    if (power >= 0) {
        for (int i = 0; i < power; i++)
            x *= 10;
    } else {
        for (int i = 0; i > power; i--)
            x /= 10;
    }
    return x;
}

int my_hypot(int side_1, int side_2)
{
    int side_1_squared = my_pow(side_1, 2);
    int side_2_squared = my_pow(side_2, 2);
    int sum_squared = side_1_squared + side_2_squared;
    int res = my_sqrt(sum_squared);

    return res;
}

double my_sqrt(double value)
{
    double x = value / 2;
    double epsilon = my_dexp(-7);

    while (my_fabs(x * x - value) > epsilon) {
        x = (x + value / x) / 2;
    }
    return x;
}
