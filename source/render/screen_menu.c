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

    int lX = infos.length/10;
    int hX = infos.height/10;

    display_rectangle(lX-20, hX-10, 40, 40, color.red, 1, 1, sfWhite);
    display_rectangle(lX+30, hX-10, 40, 40, color.yellow, 1, 1, sfWhite);
    display_rectangle(lX+80, hX-10, 40, 40, color.cyan, 1, 1, sfWhite);

    char *hour = get_exact_time_in_string(timeinfo->tm_hour);
    char *min = get_exact_time_in_string(timeinfo->tm_min);
    char *sec = get_exact_time_in_string(timeinfo->tm_sec);

    display_text(hour, lX,    hX, sfWhite, 30, 1);
    display_text(min, lX + 50,    hX, sfWhite, 30, 1);
    display_text(sec, lX + 100,    hX, sfWhite, 30, 1);

    free(hour);
    free(min);
    free(sec);
}

void render_title(void)
{
    display_rectangle(infos.length/2-20, infos.height/10, 100, 100, color.red, 0, 0, sfWhite);

    display_text("TUSMO", infos.length/2, infos.height/10, sfWhite, 100, 1);
}


void render_menu(void)
{
    render_current_time();
    render_title();

    display_picture("assets/tusmo.png", infos.length/2, 5*infos.height/6, 0.5f, 1);

    display_picture("assets/menu_button.png", infos.length/2, infos.height/2, 1.0f, 1);


    
}

