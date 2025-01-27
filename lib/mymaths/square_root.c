/*
** EPITECH PROJECT, 2025
** Project_Template
** File description:
** square_root
*/

#include "mymaths.h"

double my_sqrt(double value)
{
    double x = value / 2;
    double epsilon = my_dexp(-7);

    while (my_fabs(x * x - value) > epsilon) {
        x = (x + value / x) / 2;
    }
    return x;
}
