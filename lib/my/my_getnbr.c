/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** A litlte file to get a int form a char*
*/

#include "my.h"

static int is_valid_digit(char possible_digit)
{
    if (possible_digit > '9' || possible_digit < '0') {
        return 0;
    }
    return 1;
}

static int process_nbr_char(char current_char, int *nbr_length,
    int *nbr_start_index, int i)
{
    if (is_valid_digit(current_char)) {
        (*nbr_start_index) = (((*nbr_start_index) == -1)
                ? i : (*nbr_start_index));
        (*nbr_length)++;
        return -1;
    } else {
        return (((*nbr_length) != 0) ? 1 : 0);
    }
    return -1;
}

static int process_nbr_sign(char current_char,
    int *nbr_start_index, int *nbr_sign)
{
    if (current_char == '+') {
        return 1;
    } else if (current_char == '-' && (*nbr_start_index) == -1) {
        (*nbr_sign) *= -1;
        return 1;
    }
    return 0;
}

// return 0 if the number is valid
static int get_nbr_info(char const *str, int *nbr_length,
    int *nbr_start_index, int *nbr_sign)
{
    char current_char = 0;
    int process_result = 0;

    (*nbr_start_index) = -1;
    (*nbr_sign) = 1;
    for (int i = 0; str[i]; i++) {
        current_char = str[i];
        if (process_nbr_sign(current_char, nbr_start_index, nbr_sign)) {
            continue;
        }
        process_result = process_nbr_char(current_char, nbr_length,
            nbr_start_index, i);
        if (process_result != -1) {
            return process_result;
        }
    }
    return 1;
}

static int build_number(const char *str, int *nbr_length,
    int *nbr_start_index, int *sign)
{
    int result = 0;
    long validation_buffer = 0;
    char current_char = 0;
    int current_exp = (*nbr_length) - 1;

    for (int i = (*nbr_start_index);
        i < ((*nbr_start_index) + (*nbr_length)); i++) {
        current_char = str[i];
        result += (my_compute_power_rec(10, current_exp) *
            (current_char - '0')) * (*sign);
        validation_buffer += (my_compute_power_rec(10, current_exp) *
            (current_char - '0')) * (*sign);
        current_exp--;
        if (validation_buffer != result) {
            return 0;
        }
    }
    return result;
}

int my_getnbr(char const *str)
{
    int result = 0;
    int nbr_length = 0;
    int nbr_start_index = 0;
    int sign = 0;

    if (get_nbr_info(str, &nbr_length, &nbr_start_index, &sign)) {
        result = build_number(str, &nbr_length, &nbr_start_index, &sign);
    }
    return result;
}
