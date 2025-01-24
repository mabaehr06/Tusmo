/*
** EPITECH PROJECT, 2024
** functions get
** File description:
** functions get
*/

#include "../../include/project.h"

int my_get_nb_len(const char *format, int i)
{
    int cpt = 1;

    while (format[i] >= '0' && format[i] <= '9') {
        i++;
        cpt *= 10;
    }
    return cpt;
}

int my_get_numbers(const char *format, int i)
{
    int p = my_get_nb_len(format, i);
    int nb = 0;

    while (format[i] >= '0' && format[i] <= '9') {
        nb += (format[i] - '0') * p;
        p /= 10;
        i++;
    }
    nb /= 10;
    return nb;
}

int get_specif(const char *format, int i)
{
    while (format[i] >= '0' && format[i] <= '9') {
        i++;
    }
    return format[i];
}

void print_specifiers(const char *format, int i, va_list list)
{
    int caract = get_specif(format, i + 1);

    if (caract == 's') {
        my_putstr(va_arg(list, char *));
    }
    if (caract == 'd' || caract == 'i' || caract == 'u') {
        my_put_nbr(va_arg(list, int));
    }
    if (caract == 'o') {
        my_unsigned_octal(va_arg(list, int));
    }
    if (caract == 'x') {
        my_puthex_low(va_arg(list, int));
    }
    if (caract == 'X') {
        my_puthex_up(va_arg(list, int));
    }
}
