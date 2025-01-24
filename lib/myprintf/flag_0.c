/*
** EPITECH PROJECT, 2024
** my printf
** File description:
** my printf
*/

#include "../../include/project.h"



int flag_0(const char *format, int i, va_list list)
{
    int num = my_get_numbers(format, i + 1);
    int total_add = 0;
    va_list list2;

    va_copy(list2, list);
    total_add = num - get_va_len(format, i, list);
    if (format[i + 1] == '0') {
        for (int j = 0; j < total_add; j++) {
            my_putchar('0');
        }
        print_specifiers(format, i, list);
        return get_format_len(format, i);
    }
    return 0;
}

int flag_number(const char *format, int i, va_list list)
{
    int num = my_get_numbers(format, i + 1);
    int total_add = 0;
    va_list list2;

    va_copy(list2, list);
    total_add = num - get_va_len(format, i, list);
    if (format[i + 1] >= '1' && format[i + 1] <= '9') {
        for (int k = 0; k < total_add; k++) {
            my_putchar(32);
        }
        print_specifiers(format, i, list);
        return get_format_len(format, i);
    }
    return 0;
}

int flag_minus(const char *format, int i, va_list list)
{
    int num = my_get_numbers(format, i + 2);
    int total_add = 0;
    va_list list2;

    va_copy(list2, list);
    total_add = num - get_va_len(format, i, list);
    if (format[i + 1] == '-') {
        print_specifiers(format, i + 1, list);
        for (int j = 0; j < total_add; j++) {
            my_putchar(32);
        }
        return get_format_len(format, i);
    }
    return 0;
}
