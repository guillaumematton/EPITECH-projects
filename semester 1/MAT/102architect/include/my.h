/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my lib
*/

#ifndef MY_H
    #define MY_H
    #define M_PI 3.14159265358979323846

int translation(char **argv, int i, int argc);
int scaling(char **argv, int i, int argc);
int rotation(char **argv, int i, int argc);
int reflection(char **argv, int i, int argc);
double *set_matrix(double *tab, char **argv, int argc);
double *multiply_matrix(double *tab, double *temptab, char **argv, int argc);
void printing_new_values(double *tab, char **argv);
int verify_argument(char **argv, int argc);
double *read_matrix(char **argv, int argc, double *tab, double *temptab);

#endif /*MY_H*/
