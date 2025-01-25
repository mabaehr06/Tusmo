/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** errors
*/

#include "../include/project.h"

int can_error_go(float start_time, float actual_time, int duration)
{
    if ((actual_time - start_time) < duration)
        return 1;
    return 0;
}

void display_error_message(char *message, int x, int y, int duration)
{
    float now = screen.elapsed_time;

    while (now - screen.elapsed_time < duration) {
        display_text(message, x, y, sfRed, 40, 0);
    }
}