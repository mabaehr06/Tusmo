/*
** EPITECH PROJECT, 2025
** Project_template
** File description:
** maximum
*/

#include "mymaths.h"

int my_max(int value_1, int value_2)
{
    if (value_1 >= value_2)
        return value_1;
    else
        return value_2;
}

float my_fmax(float value_1, float value_2)
{
    if (value_1 >= value_2)
        return value_1;
    else
        return value_2;
}
