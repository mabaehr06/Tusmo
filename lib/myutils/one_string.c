/*
** EPITECH PROJECT, 2025
** Project_Template
** File description:
** one_string
*/

#include "myutils.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int get_len_of_all_words(int len, va_list list)
{
    char *actual_word = "";
    int size = 0;

    for (int i = 0; i < len; i++) {
        actual_word = va_arg(list, void *);
        for (int j = 0; actual_word[j] != '\0'; j++) {
            size++;
        }
    }
    return size;
}

char *one_string(int len, ...)
{
    va_list list;
    va_list list_copy;
    char *new_string_malloc = "";
    int size = 0;
    int letter = 0;
    char *word = "";

    va_start(list, len);
    va_copy(list_copy, list);
    size = get_len_of_all_words(len, list_copy);
    new_string_malloc = malloc((size + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        word = va_arg(list, void *);
        for (int i = 0; word[i] != '\0'; i++) {
            new_string_malloc[letter] = word[i];
            letter++;
        }
    }
    new_string_malloc[size] = '\0';
    return new_string_malloc;
}
