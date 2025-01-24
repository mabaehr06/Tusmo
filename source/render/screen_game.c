/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** render
*/

#include "../../include/project.h"

char *convert_into_time(char *string, char *type)
{
    if (my_strcmp(type, "min")) {
        return string;
    }
    return string;
}

void render_game_time(void)
{
    char *string_time = int_to_str((int)my_trunc(screen.elapsed_time));

    string_time = convert_into_time(string_time, "min");
    if (screen.elapsed_time < 1) {
        string_time[0] = '0';
        string_time[1] = '\0';
    }

    display_text(string_time, (infos.length/6), 350, sfWhite, 50, 0);
}

void render_all_words(void)
{
    int i = 0;
    int midh = infos.height / 2;
    int midl = infos.length / 2;
    int j = -250;
    while (i < 6) {
        show_row(midl - 250, midh + j, words.warray[i]);
        i++;
        j+=100;
    }
}

void render_game(void)
{
    screen.elapsed_time = sfTime_asSeconds(sfClock_getElapsedTime(screen.clock));
    if (screen.elapsed_time >= TIMEOUT)
        end_application();
    
    display_picture("assets/tusmo.png", infos.length/6, 150, 0.5f, 1);
    edit_word();
    render_game_time();
    render_all_words();
}
