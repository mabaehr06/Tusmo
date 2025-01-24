/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

// B-CPE-100
// Day 01 && 02 == SHELL
// ---------------------
// Day 03
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);

// Day 04
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);

// Day 05
int my_is_prime(int nb);
int my_compute_square_root(int nb);
int my_compute_power_rec(int nb, int power);

// Day 06
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);

// Day 07
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

// Day 08
char *my_strdup(char const *src);


#endif
