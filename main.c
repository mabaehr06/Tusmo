/*
** EPITECH PROJECT, 2024
** Template_Project
** File description:
** main
*/

#include "include/project.h"

struct infos infos;
struct words words;
struct screen screen;
struct settings settings;
struct color color;

void show_rectangle(int x, int y, char *string, int index)
{
    char *str = malloc(2 * sizeof(char));
    sfColor color = get_color_off(string, index);
    sfRectangleShape *rect = sfRectangleShape_create();

    str[0] = string[index];
    str[1] = '\0';
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setPosition(rect, (sfVector2f){x, y});
    sfRectangleShape_setSize(rect, (sfVector2f){75, 75});
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRenderWindow_drawRectangleShape(infos.window, rect, NULL);
    display_text(str, x+15, y+3, sfWhite, 54, 0);
    free(str);
    sfRectangleShape_destroy(rect);
}

void show_row(int x, int y, char *string)
{
    for (int i = 0; i != 6; i++) {
        show_rectangle(x+(79*i), y, string, i);
    }
}

void edit_word(void)
{
    for (int i = 0; i < 6; i++) {
        if (i == words.actual_id) {
            words.warray[i][0] = words.to_found[0]; 
            for (int j = 0; words.warray[i][j] != '\0'; j++) {
                if (words.warray[i][j] == ' ') {
                    if (words.warray[i][j] == words.to_found[j])
                        words.warray[i][j] = words.to_found[j];
                    else
                        words.warray[i][j] = '.';
                }
            }
            break;
        }
    }
}

int main(void)
{
    sfEvent event;

    init();
    word_to_get();
    while (sfRenderWindow_isOpen(infos.window)) {
        carry_event(event);
        sfRenderWindow_clear(infos.window,color.black_cyan);
        render();


        for (int i = 0; i != settings.nb_games; i++) {
            printf("Game %d\n", i);
            for (int j = 0; j != 6; j++) {
                printf("%d: %s \n", j, words.all_games[i][j]);
            }
            printf("\n");
        }



        sfRenderWindow_display(infos.window);
    }
}
