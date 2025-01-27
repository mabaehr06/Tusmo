/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** draw_utils
*/

#include "../../include/project.h"

// return an sfVector2f of {x, y}
sfVector2f sfv2f(int x, int y)
{
    return (sfVector2f){x, y};
}


// return an sfVector2i of {x, y}
sfVector2i sfv2i(int x, int y)
{
    return (sfVector2i){x, y};
}




// void display_rectangle_corner(sfRenderWindow *window, sfVector2f position, sfVector2f size, float radius, sfColor color)
// {
//     // 1. Dessiner les quatre arcs (coins arrondis)
//     sfCircleShape *corner = sfCircleShape_create();
//     sfCircleShape_setRadius(corner, radius);
//     sfCircleShape_setFillColor(corner, color);

//     // Top-left corner
//     sfCircleShape_setPosition(corner, position);
//     sfRenderWindow_drawCircleShape(window, corner, NULL);

//     // Top-right corner
//     sfCircleShape_setPosition(corner, (sfVector2f){position.x + size.x - 2 * radius, position.y});
//     sfRenderWindow_drawCircleShape(window, corner, NULL);

//     sfCircleShape_setPosition(corner, (sfVector2f){position.x, position.y + size.y - 2 * radius});
//     sfRenderWindow_drawCircleShape(window, corner, NULL);

//     sfCircleShape_setPosition(corner, (sfVector2f){position.x + size.x - 2 * radius, position.y + size.y - 2 * radius});
//     sfRenderWindow_drawCircleShape(window, corner, NULL);

//     sfRectangleShape *rectangle = sfRectangleShape_create();
//     sfRectangleShape_setSize(rectangle, (sfVector2f){size.x - 2 * radius, radius});
//     sfRectangleShape_setFillColor(rectangle, color);

//     sfRectangleShape_setPosition(rectangle, (sfVector2f){position.x + radius, position.y});
//     sfRenderWindow_drawRectangleShape(window, rectangle, NULL);

//     sfRectangleShape_setPosition(rectangle, (sfVector2f){position.x + radius, position.y + size.y - radius});
//     sfRenderWindow_drawRectangleShape(window, rectangle, NULL);

//     sfRectangleShape_setSize(rectangle, (sfVector2f){radius, size.y - 2 * radius});
//     sfRectangleShape_setPosition(rectangle, (sfVector2f){position.x, position.y + radius});
//     sfRenderWindow_drawRectangleShape(window, rectangle, NULL);

//     sfRectangleShape_setPosition(rectangle, (sfVector2f){position.x + size.x - radius, position.y + radius});
//     sfRenderWindow_drawRectangleShape(window, rectangle, NULL);

//     sfRectangleShape_setSize(rectangle, (sfVector2f){size.x - 2 * radius, size.y - 2 * radius});
//     sfRectangleShape_setPosition(rectangle, (sfVector2f){position.x + radius, position.y + radius});
//     // sfRenderWindow_drawRectangleShape(window, rectangle, NULL);

//     sfCircleShape_destroy(corner);
//     sfRectangleShape_destroy(rectangle);
// }