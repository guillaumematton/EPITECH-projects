/*
** EPITECH PROJECT, 2024
** my put nbr
** File description:
** print a number
*/

#include "my.h"
#include <unistd.h>

int lines(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb *= -1;
    }
    return nb;
}

int my_put_nbr(int nb)
{
    int midnb = 0;
    int s = 1;
    int i;

    if (nb == 0)
        my_putchar('0');
    nb = lines(nb);
    for (i = 0; nb != 0; i++){
        midnb *= 10;
        midnb += nb % 10;
        nb -= nb % 10;
        nb = nb / 10;
    }
    for (; i > 0; i--){
        my_putchar((midnb % 10) + 48);
        midnb -= nb % 10;
        midnb /= 10;
    }
}
