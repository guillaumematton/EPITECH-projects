/*
** EPITECH PROJECT, 2024
** my swap
** File description:
** invert a and b location
*/

#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
