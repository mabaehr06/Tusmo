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

float my_nth_root(float A, int n)
{
    const int K = 6;
    float x[K];

    for (int i = 0; i < K; i++)
        x[i] = 1.0;
    for (int k = 0; k < K - 1; k++)
        x[k + 1] = (1.0 / n) * ((n - 1) * x[k] + A / my_powf(x[k], n - 1));
    return x[K - 1];
}

float my_powf(float base, float ex)
{
    float half_pow = 0;

    if (base == 0)
        return 0;
    if (ex == 0)
        return 1;
    if (ex < 0)
        return 1 / my_powf(base, - ex);
    if (ex > 0 && ex < 1)
        return my_nth_root(base, 1 / ex);
    if ((int)ex % 2 == 0){
        half_pow = my_powf(base, ex / 2);
        return half_pow * half_pow;
    }
    return base * my_powf(base, ex - 1);
}
