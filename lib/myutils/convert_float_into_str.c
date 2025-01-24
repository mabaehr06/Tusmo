/*
** EPITECH PROJECT, 2025
** Project_template
** File description:
** convert_float_into_str
*/

#include <stdio.h>
#include "myutils.h"

char *convert_float_into_str(float number, int precision)
{
    float fractional_part = number - (int)number;
    char *result = malloc(sizeof(char) * (get_len_of_int((int)number) + 12));
    int integer_digits = get_len_of_int((int)number);
    int pos = 0;

    for (int i = 0; i < integer_digits; i++) {
        result[pos + integer_digits - 1 - i] = '0' + ((int)number % 10);
        number /= 10;
    }
    pos += integer_digits;
    result[pos] = '.';
    pos++;
    for (int i = 0; i < precision; i++) {
        fractional_part *= 10;
        result[pos] = '0' + (int)fractional_part;
        fractional_part -= (int)fractional_part;
        pos++;
    }
    result[pos] = '\0';
    return result;
}
