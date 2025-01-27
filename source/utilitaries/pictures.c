/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** pictures
*/

#include "../../include/project.h"

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