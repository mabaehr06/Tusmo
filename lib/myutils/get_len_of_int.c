/*
** EPITECH PROJECT, 2024
** Template_Project
** File description:
** get_len_of_int
*/

#include "../my/my.h"
#include "myutils.h"


int get_len_of_int(int number)
{
    int i = 0;

    while (number > 0) {
        number /= 10;
        i++;
    }
    return i;
}
