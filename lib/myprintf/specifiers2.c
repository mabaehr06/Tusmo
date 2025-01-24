/*
** EPITECH PROJECT, 2024
** my printf
** File description:
** my printf
*/

#include "../../include/project.h"

int specif_p(const char *format, int i, va_list list)
{
    if (format[i + 1] == 'p') {
        my_putpoint(va_arg(list, void *));
        return 1;
    }
    return 0;
}
