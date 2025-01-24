/*
** EPITECH PROJECT, 2025
** Project_template
** File description:
** rounding
*/

#include "mymaths.h"

double my_round(double number)
{
    int number_integer = (int)number;

    if (number - number_integer >= 0.5) {
        return (int)number + 1;
    }
    if (number - number_integer <= -0.5) {
        return (int)number - 1;
    }
    return (int)number;
}

double my_trunc(double number)
{
    return (int)number;
}

double my_ceil(double number)
{
    if (number < 0 && number > -1)
        return 0;
    if (number < 0)
        return (int)number;
    return (int)number + 1;
}
