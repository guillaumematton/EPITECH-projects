/*
** EPITECH PROJECT, 2024
** my isneg
** File description:
** return pos or neg
*/

#include "../../include/my.h"

int my_isneg(int n)
{
    if (n < 0){
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
