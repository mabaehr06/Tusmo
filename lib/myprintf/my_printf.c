/*
** EPITECH PROJECT, 2024
** le f affficher
** File description:
** le f afficherrr
*/

#include "../../include/project.h"

int params(const char *format, int i, va_list list)
{
    int add = 0;

    if (format[i + 1] >= '0')
        add += flag_0(format, i, list);
    if (format[i + 1] >= '1' && format[i + 1] <= '9')
        add += flag_number(format, i, list);
    if (format[i + 1] == '#')
        add += flag_diese(format, i, list);
    if (format[i + 1] == '-')
        add += flag_minus(format, i, list);
    return add;
}

int conversions(char const *format, int i, va_list list)
{
    int add = 1;

    add += params(format, i, list);
    add += specif_p(format, i, list);
    add += specif_id(format, i, list);
    add += specif_sc(format, i, list);
    add += specif_oux(format, i, list);
    add += specif_pct(format, i);
    add += specif_efg(format, i, list);
    return add;
}

int my_printf(char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] != '%') {
            my_putchar(format[i]);
            i++;
        }
        if (format[i] == '%') {
            i += conversions(format, i, list);
        }
    }
    va_end(list);
    return 0;
}
