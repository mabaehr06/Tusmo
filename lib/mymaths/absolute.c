/*
** EPITECH PROJECT, 2025
** Project_template
** File description:
** maths
*/

#include "mymaths.h"

int my_abs(int value)
{
    if (value >= 0) {
        return value;
    } else {
        return - value;
    }
}

float my_fabs(float value)
{
    if (value >= 0)
        return value;
    else
        return - value;
}
