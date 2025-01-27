/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** texts
*/

#include "../../include/project.h"

void display_text(char *string, int x, int y, sfColor color, int size, int center)
{
    sfText* text = sfText_create();

    sfText_setColor(text, color);
    sfText_setFont(text, infos.font);
    sfText_setCharacterSize(text, size);
    sfText_setString(text, string);
    if (center) {
        sfFloatRect offset = sfText_getGlobalBounds(text);

        sfText_setPosition(text, (sfVector2f)
        {
            x - (offset.width / 2.0f),
            y - (offset.height / 2.0f)
        });
    } else {
        sfText_setPosition(text, (sfVector2f){x, y});
    }
    sfRenderWindow_drawText(infos.window, text, NULL);
    sfText_destroy(text);
}