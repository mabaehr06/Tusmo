/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** corner_rectangle
*/

#include "../../include/project.h"

static void draw_circles(sfVector2f position, sfVector2f size, float radius, sfColor color)
{
    sfCircleShape *corner = sfCircleShape_create();
    sfCircleShape_setRadius(corner, radius);
    sfCircleShape_setFillColor(corner, color);

    // Ox
    // xx
    sfCircleShape_setPosition(corner, position);
    sfRenderWindow_drawCircleShape(infos.window, corner, NULL);

    // xO
    // xx
    sfCircleShape_setPosition(corner, (sfVector2f){position.x + size.x - 2 * radius, position.y});
    sfRenderWindow_drawCircleShape(infos.window, corner, NULL);

    // xx
    // Ox
    sfCircleShape_setPosition(corner, (sfVector2f){position.x, position.y + size.y - 2 * radius});
    sfRenderWindow_drawCircleShape(infos.window, corner, NULL);

    // xx
    // xO
    sfCircleShape_setPosition(corner, (sfVector2f){position.x + size.x - 2 * radius, position.y + size.y - 2 * radius});
    sfRenderWindow_drawCircleShape(infos.window, corner, NULL);

    sfCircleShape_destroy(corner);
}


static void draw_w_e_rectangle(sfVector2f position, sfVector2f size, float radius, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rectangle, color);

    sfRectangleShape_setSize(rectangle, (sfVector2f){radius, size.y - 2 * radius});

    sfRectangleShape_setPosition(rectangle, (sfVector2f){position.x, position.y + radius});
    sfRenderWindow_drawRectangleShape(infos.window, rectangle, NULL);

    sfRectangleShape_setPosition(rectangle, (sfVector2f){position.x + size.x - radius, position.y + radius});
    sfRenderWindow_drawRectangleShape(infos.window, rectangle, NULL);

    sfRectangleShape_destroy(rectangle);
}

static void draw_n_s_rectangle(sfVector2f position, sfVector2f size, float radius, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rectangle, color);

    sfRectangleShape_setSize(rectangle, (sfVector2f){size.x - 2 * radius, radius});

    sfRectangleShape_setPosition(rectangle, (sfVector2f){position.x + radius, position.y});
    sfRenderWindow_drawRectangleShape(infos.window, rectangle, NULL);

    sfRectangleShape_setPosition(rectangle, (sfVector2f){position.x + radius, position.y + size.y - radius});
    sfRenderWindow_drawRectangleShape(infos.window, rectangle, NULL);

    sfRectangleShape_destroy(rectangle);
}

static void draw_fill_rectangle(sfVector2f position, sfVector2f size, float radius, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rectangle, color);

    sfRectangleShape_setSize(rectangle, (sfVector2f){size.x - 2 * radius, size.y - 2 * radius});

    sfRectangleShape_setPosition(rectangle, (sfVector2f){position.x + radius, position.y + radius});
    sfRenderWindow_drawRectangleShape(infos.window, rectangle, NULL);

    sfRectangleShape_destroy(rectangle);
}


void display_rectangle_corner(sfVector2f position, sfVector2f size, float radius, sfColor color, int is_centered)
{
    if (is_centered) {
        position.x -= size.x/2;
        position.y -= size.y/2;
    }
    draw_circles(position, size, radius, color);
    draw_n_s_rectangle(position, size, radius, color);
    draw_w_e_rectangle(position, size, radius, color);
    draw_fill_rectangle(position, size, radius, color);
}