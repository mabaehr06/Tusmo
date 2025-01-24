/*
** EPITECH PROJECT, 2024
** ::
** File description:
** ::
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
