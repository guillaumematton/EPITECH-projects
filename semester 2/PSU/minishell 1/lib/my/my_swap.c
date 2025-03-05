/*
** EPITECH PROJECT, 2024
** my swap
** File description:
** swap two variables
*/

#include "../../include/lib.h"

void my_swap(int *a, int *b)
{
    int c = *b;

    *b = *a;
    *a = c;
}
