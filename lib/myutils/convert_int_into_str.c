/*
** EPITECH PROJECT, 2024
** Template_Project
** File description:
** convert_int_into_str
*/

#include "myutils.h"

char *int_to_str(int number)
{
    int i = 0;
    int k;
    int len = get_len_of_int(number);
    char *str = malloc(sizeof(char) * len + 1);
    char temp;

    while (number > 0) {
        str[i] = number % 10 + '0';
        number /= 10;
        i++;
    }
    str[i] = '\0';
    k = i - 1;
    for (int j = 0; j < k; j++) {
        temp = str[j];
        str[j] = str[k];
        str[k] = temp;
        k--;
    }
    return str;
}
