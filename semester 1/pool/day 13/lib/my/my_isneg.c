/*
** EPITECH PROJECT, 2024
** integers sign
** File description:
** positive or negative
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
