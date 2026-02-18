/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** normal_rectangle
*/

#include "../../include/project.h"

void display_rectangle(int sx, int sy, int tx, int ty, sfColor fill_color, int has_outline, int outline_thickness, sfColor outline_color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (sfVector2f){sx, sy});
    sfRectangleShape_setSize(rect, (sfVector2f){tx, ty});
    sfRectangleShape_setFillColor(rect, fill_color);
    if (has_outline) {
        sfRectangleShape_setOutlineColor(rect, outline_color);
        sfRectangleShape_setOutlineThickness(rect, outline_thickness);
    }
    sfRenderWindow_drawRectangleShape(infos.window, rect, 0);
    sfRectangleShape_destroy(rect);
}