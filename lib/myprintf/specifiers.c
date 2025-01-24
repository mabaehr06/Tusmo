/*
** EPITECH PROJECT, 2024
** my printf
** File description:
** my printf
*/

#include "../../include/project.h"

int specif_id(const char *format, int i, va_list list)
{
    if (format[i + 1] == 'i') {
        my_put_nbr(va_arg(list, int));
        return 1;
    }
    if (format[i + 1] == 'd') {
        my_put_nbr(va_arg(list, int));
        return 1;
    }
    return 0;
}

int specif_sc(const char *format, int i, va_list list)
{
    if (format[i + 1] == 's') {
        my_putstr(va_arg(list, char *));
        return 1;
    }
    if (format[i + 1] == 'c') {
        my_putchar(va_arg(list, int));
        return 1;
    }
    return 0;
}

int specif_oux(const char *format, int i, va_list list)
{
    if (format[i + 1] == 'o') {
        my_unsigned_octal(va_arg(list, int));
        return 1;
    }
    if (format[i + 1] == 'u') {
        my_put_nbr(va_arg(list, int));
        return 1;
    }
    if (format[i + 1] == 'x') {
        my_puthex_low(va_arg(list, int));
        return 1;
    }
    if (format[i + 1] == 'X') {
        my_puthex_up(va_arg(list, int));
        return 1;
    }
    return 0;
}

int specif_pct(const char *format, int i)
{
    if (format[i + 1] == '%') {
        my_putchar('%');
        return 1;
    }
    return 0;
}

int specif_efg(const char *format, int i, va_list list)
{
    if (format[i + 1] == 'e') {
        return 1;
    }
    if (format[i + 1] == 'f') {
        my_put_float(va_arg(list, double));
        return 1;
    }
    if (format[i + 1] == 'g') {
        return 1;
    }
    return 0;
}
