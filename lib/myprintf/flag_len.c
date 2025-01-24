/*
** EPITECH PROJECT, 2024
** my printf
** File description:
** my printf
*/

#include "../../include/project.h"

int get_nb_len(int nb)
{
    int cpt = 1;

    while (nb > 10) {
        cpt++;
        nb /= 10;
    }
    return cpt;
}

int get_specifier(const char *format, int i)
{
    while ((format[i] != 'd') && (format[i] != 'i') && (format[i] != 's') &&
    (format[i] != 'c') && (format[i] != 'o') && (format[i] != 'u') &&
    (format[i] != 'x') && (format[i] != 'X')) {
        i++;
    }
    return format[i];
}

int get_va_len(const char *format, int i, va_list list)
{
    char type = get_specifier(format, i);
    va_list ap;

    va_copy(ap, list);
    if (type == 'd' || type == 'i' || type == 'u' ||
    type == 'o' || type == 'x' || type == 'X') {
        return get_nb_len(va_arg(ap, int));
    }
    if (type == 's') {
        return my_strlen(va_arg(ap, char *));
    }
    if (type == 'c') {
        return 1;
    }
    return 0;
}

int get_format_len(const char *format, int i)
{
    int cpt = 0;

    while ((format[i] != 'd') && (format[i] != 'i') && (format[i] != 's') &&
    (format[i] != 'c') && (format[i] != 'o') && (format[i] != 'u') &&
    (format[i] != 'x') && (format[i] != 'X')) {
        i++;
        cpt++;
    }
    return cpt;
}
