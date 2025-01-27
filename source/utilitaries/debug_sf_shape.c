/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** debug_sf_shape
*/

#include "../../include/project.h"

void debug_line_Y(int position_x, sfColor color)
{
    display_rectangle(position_x, 0, 1, infos.height, color, 0, 0, sfWhite);
}


void debug_line_X(int position_x, sfColor color)
{
    display_rectangle(0, position_x, infos.length, 1, color, 0, 0, sfWhite);
}