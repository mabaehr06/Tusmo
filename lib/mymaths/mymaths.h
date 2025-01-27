/*
** EPITECH PROJECT, 2025
** Template_Project
** File description:
** mymaths
*/


#ifndef INCLUDE_MYMATHS_H
    #define INCLUDE_MYMATHS_H

// #define PI  3.14159265358979323846264338327950288419716939937510

// absolute.c
int my_abs(int value);
float my_fabs(float value);

// maximum.c
int my_max(int value_1, int value_2);
float my_fmax(float value_1, float value_2);

// minimum.c
int my_min(int value_1, int value_2);
float my_fmin(float value_1, float value_2);

// power_functions.c
int my_pow(int number, int power);
int my_hypot(int side_1, int side_2);
double my_dexp(double power);
float my_nth_root(float A, int n);
float my_powf(float base, float ex);

// rounding.c
double my_round(double number);
double my_trunc(double number);
double my_ceil(double number);

// square_root.c
double my_sqrt(double value);


#endif
