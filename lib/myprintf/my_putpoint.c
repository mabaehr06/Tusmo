/*
** EPITECH PROJECT, 2024
** my putpoint
** File description:
** my putpoint
*/

#include "../../include/project.h"

void my_putpoint(const void *ptr)
{
    unsigned long adr = (unsigned long)ptr;
    char base[] = "0123456789abcdef";
    char buff[18];
    int i = 17;

    buff[2] = '\0';
    while (adr > 0) {
        buff[i] = base[adr % 16];
        adr /= 16;
        i--;
    }
    my_putchar('0');
    my_putchar('x');
    write(1, buff + i + 1, 17 - i);
}
