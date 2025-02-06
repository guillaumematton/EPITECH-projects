/*
** EPITECH PROJECT, 2024
** my put nbr
** File description:
** display number given as parameter
*/

#include "../../include/my.h"

int my_nbrlength(int nb)
{
    int i = 0;

    while (nb > 0) {
        nb /= 10;
        i++;
    }
    return (i);
}

int pow1(int i)
{
    int l = 10;

    while (i > 2){
        l *= 10;
        i--;
    }
    return (l);
}

static int limmin(int nb)
{
    int l;
    int power;

    nb /= -10;
    my_putchar('-');
    l = my_nbrlength(nb);
    power = pow1(l);
    for (; power != 0; power /= 10){
        my_putchar((nb / power) + 48);
        nb = nb - ((nb / power) * power);
    }
    my_putchar('8');
    return 0;
}

int function(int nb)
{
    if (nb == 0){
        my_putchar('0');
    }
    return (nb);
}

int myif(int nb)
{
    int n;

    if (nb == -2147483648){
        limmin(nb);
        return 1;
    }
    if (nb < 0){
        my_putchar('-');
        nb *= -1;
    }
    if (nb < 10){
        n = nb;
        my_putchar(n + 48);
        return 1;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    int time = 0;
    int l = 0;
    int power = 0;

    if (myif(nb) == 1){
        return 0;
    }
    if (nb < 0){
        nb *= -1;
    }
    myif(nb);
    function(nb);
    l = my_nbrlength(nb);
    power = pow1(l);
    for (; power != 0; power /= 10){
        my_putchar((nb / power) + 48);
        nb = nb - ((nb / power) * power);
        time++;
    }
    return l;
}
