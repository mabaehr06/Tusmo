/*
** EPITECH PROJECT, 2024
** Template_Project
** File description:
** my_printf
*/

#ifndef INCLUDED_MY_PRINTF_H
    #define INCLUDED_MY_PRINTF_H

int my_printf(char *format, ...);
int my_unsigned_octal(unsigned int nb);
void my_puthex_low(unsigned int nb);
void my_puthex_up(unsigned int nb);
void my_put_float(float nb);
int specif_id(const char *format, int i, va_list list);
int specif_sc(const char *format, int i, va_list list);
int specif_oux(const char *format, int i, va_list list);
int specif_p(const char *format, int i, va_list list);
int specif_pct(const char *format, int i);
int specif_efg(const char *format, int i, va_list list);
int my_get_numbers(const char *format, int i);
int flag_0(const char *format, int i, va_list list);
int flag_diese(const char *format, int i, va_list list);
int flag_minus(const char *format, int i, va_list list);
int flag_number(const char *format, int i, va_list list);
void print_specifiers(const char *format, int i, va_list list);
int calcul_point_nb1(float float_point_nb, float dec_point_nb);
int calcul_point_nb2(float float_point_nb2, float dec_point_nb2);
int get_va_len(const char *format, int i, va_list list);
int get_format_len(const char *format, int i);
int get_nb_len(int nb);
void my_putpoint(const void *ptr);

#endif
