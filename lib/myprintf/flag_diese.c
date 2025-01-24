/*
** EPITECH PROJECT, 2024
** my printf
** File description:
** my printf
*/

#include "../../include/project.h"


int flag_diese(const char *format, int i, va_list list)
{
    char specifier = format[i + 2];

    if (format[i + 1] == '#') {
        if (specifier == 'o') {
            my_put_nbr(0);
            my_unsigned_octal(va_arg(list, int));
        }
        if (specifier == 'x') {
            my_putstr("0x");
            my_puthex_low(va_arg(list, int));
        }
        if (specifier == 'X') {
            my_putstr("0X");
            my_puthex_up(va_arg(list, int));
        }
        return 2;
    }
    return 0;
}
