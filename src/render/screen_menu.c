/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** screen_menu
*/

#include "../../include/project.h"

char *get_exact_time_in_string(int number)
{
    char *string = malloc(3 * sizeof(char));

    string[0] = number/10 + '0';
    string[1] = number%10 + '0';
    string[2] = '\0';
    return string;
}

void render_current_time(void)
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime (&rawtime);

    char *hour = get_exact_time_in_string(timeinfo->tm_hour);
    char *min = get_exact_time_in_string(timeinfo->tm_min);
    char *sec = get_exact_time_in_string(timeinfo->tm_sec);


    display_rectangle_corner(sfv2f(infos.length/10, infos.height/10), sfv2f(200, 50), 10, sfWhite, 1);
    
    display_text(hour, infos.length/10 - 50, infos.height/12, sfBlack, 36, 1);
    display_text(min, infos.length/10, infos.height/12, sfBlack, 36, 1);
    display_text(sec, infos.length/10 + 50, infos.height/12, sfBlack, 36, 1);

    free(hour);
    free(min);
    free(sec);
}

void render_title(void)
{
    sfVector2f pos = (sfVector2f)          {infos.length/2, infos.height/10};
    sfVector2f size = (sfVector2f)         {300, 100};

    display_rectangle_corner(pos, size, 40, sfWhite, 1);
    display_rectangle_corner(pos, size, 50, color.dark_cyan, 1);
    display_text("TUSMO", infos.length/2, infos.height/12, sfWhite, 60, 1);
}

void render_game_button(void)
{
    sfVector2f pos = (sfVector2f)          {(infos.length/2), (4*infos.height/5)};
    sfVector2f size = (sfVector2f)         {400, 100};

    display_rectangle_corner(pos, size, 40, sfWhite, 1);
    display_rectangle_corner(pos, size, 50, color.dark_cyan, 1);
    display_text("NEW GAME", pos.x-10, pos.y-10, sfWhite, 36, 1);
}


void render_game_number_button(void)
{
    sfVector2f pos = (sfVector2f)          {(infos.length/4), (4*infos.height/5)};
    sfVector2f size = (sfVector2f)         {200, 50};

    char *games = one_string(3, "Games : [", int_to_str(settings.nb_games), "] ");


    display_rectangle_corner(pos, size, 10, sfWhite, 1);
    display_rectangle_corner(pos, size, 15, color.dark_cyan, 1);
    display_text(games, pos.x-10, pos.y-10, sfWhite, 24, 1);
}


void render_menu(void)
{
    render_title();
    render_game_button();
    render_game_number_button();
    render_current_time();


}
