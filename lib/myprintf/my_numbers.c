/*
** EPITECH PROJECT, 2024
** functions numbers
** File description:
** functions numbers
*/

#include "../../include/project.h"

int my_unsigned_octal(unsigned int nb)
{
    int i = 0;

    if (nb > 0) {
        i = 1 + my_unsigned_octal(nb / 8);
        my_put_nbr(nb % 8);
    }
    return i;
}

void my_puthex_low(unsigned int hex)
{
    char base[] = "0123456789abcdef";
    char buff[18];
    int i = 17;

    buff[2] = '\0';
    while (hex > 0) {
        buff[i] = base[hex % 16];
        hex /= 16;
        i--;
    }
    write(1, buff + i + 1, 17 - i);
}

void my_puthex_up(unsigned int hex)
{
    char base[] = "0123456789ABCDEF";
    char buff[18];
    int i = 17;

    buff[2] = '\0';
    while (hex > 0) {
        buff[i] = base[hex % 16];
        hex /= 16;
        i--;
    }
    write(1, buff + i + 1, 17 - i);
}
