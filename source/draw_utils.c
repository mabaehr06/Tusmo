/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** draw_utils
*/

#include "../include/project.h"

void display_text(char *string, int x, int y, sfColor color, int size, int center)
{
    sfText* text = sfText_create();

    sfText_setColor(text, color);
    sfText_setFont(text, infos.font);
    sfText_setCharacterSize(text, size);
    sfText_setString(text, string);

    if (center == 1) {
        sfFloatRect offset = sfText_getGlobalBounds(text);

        sfText_setPosition(text, (sfVector2f)
        {
            x - (offset.width / 2.0f),
            y - (offset.height / 2.0f)
        });
    } else {
        sfText_setPosition(text, (sfVector2f){x, y});
    }

    sfText_setPosition(text, (sfVector2f){x, y});
    sfRenderWindow_drawText(infos.window, text, NULL);
    sfText_destroy(text);
}

void display_picture(char *path, int x, int y, float scale, int center)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setScale(sprite, (sfVector2f){scale, scale});

    if (center == 1) {
        sfFloatRect offset = sfSprite_getGlobalBounds(sprite);

        sfSprite_setPosition(sprite, (sfVector2f)
        {
            x - (offset.width / 2.0f),
            y - (offset.height / 2.0f)
        });
    } else {
        sfSprite_setPosition(sprite, (sfVector2f){x, y});
    }


    sfRenderWindow_drawSprite(infos.window, sprite, 0);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

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
