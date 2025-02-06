/*
** EPITECH PROJECT, 2024
** g, G
** File description:
** more functions
*/

#include "include/my.h"
#include <stdlib.h>

int pconv(void *fake, int uporlow)
{
    long toconvert = (long)fake;
    char *oconvert = malloc(sizeof(char) * 15);

    for (int i = 0; toconvert != 0; i++){
        if (toconvert % 16 < 10)
            oconvert[i] = toconvert % 16 + 48;
        else
            oconvert[i] = toconvert % 16 + 87;
        toconvert -= toconvert % 16;
        toconvert /= 16;
    }
    if (uporlow == 1)
        oconvert = my_strupcase(oconvert);
    my_putstr(my_revstr(oconvert));
    return my_strlen(oconvert);
}

static int testing_for_the_0s(int nbrtemp, int g)
{
    if (nbrtemp < 1){
        my_putchar('0');
        g++;
    }
    return g;
}

static int print_ifrounder(int valin, int precision, int testnbr, int i)
{
    int nbrtemp = testnbr;
    int g = 0;

    g += my_put_nbr(valin);
    if (testnbr != 0){
        my_putchar('.');
        g++;
        for (; i < precision - 1; i++){
            nbrtemp /= 10;
            g = testing_for_the_0s(nbrtemp, g);
        }
        g += my_put_nbr(testnbr);
    }
    return g;
}

static int rounding(int testnbr)
{
    if (testnbr % 10 >= 5){
        testnbr /= 10;
        testnbr += 1;
    } else
        testnbr /= 10;
    return testnbr;
}

static int following_of_ifrounder(double nbr, int i, int precision, int valin)
{
    int r = 0;
    int testnbr = 0;
    int j = 2;

    for (r = 0; r < precision; r++)
        nbr *= 10;
    testnbr = nbr;
    for (; testnbr % 10 == 0 && testnbr >= 1; j++){
        nbr /= 10;
        testnbr = nbr;
    }
    testnbr = rounding(testnbr);
    for (; testnbr % 10 == 0; j++)
        testnbr /= 10;
    if (testnbr == my_compute_power_rec(10, r - i)){
        valin++;
        testnbr = 0;
    }
    valin = print_ifrounder(valin, precision, testnbr, j);
    return valin;
}

static int ifrounder(double nbr, int i, int g, int precision)
{
    int testnbr = 0;
    int valin = 0;
    int l = 0;

    while (nbr >= 1){
        nbr /= 10;
        l++;
    }
    for (; l > 0 && i < precision; i++){
        nbr *= 10;
        valin *= 10;
        testnbr = nbr;
        valin += testnbr;
        nbr -= testnbr;
        l--;
    }
    g += following_of_ifrounder(nbr, i, precision, valin);
    return g;
}

static int following_of_localscience(int pui, int g)
{
    if (pui >= 0)
        my_putchar('+');
    else {
        pui *= -1;
        my_putchar('-');
    }
    g++;
    if (pui < 10){
        my_putchar('0');
        g++;
    }
    g += my_put_nbr(pui);
    return g;
}

static int localscience(double nbr, int uporlow, int g, int precision)
{
    int pui = 0;

    for (; nbr < 1; pui--)
        nbr *= 10;
    for (; nbr >= 10; pui++)
        nbr /= 10;
    if (nbr + (my_compute_power_rec(10, -5)) >= 10)
        pui++;
    g += ifrounder(nbr, 0, g, precision);
    if (uporlow == 1){
        my_putchar('E');
        g++;
    } else {
        my_putchar('e');
        g++;
    }
    g += following_of_localscience(pui, g);
    return g;
}

int mixscirou(double nbr, int uporlow, int precision)
{
    int l = 0;
    int i = 0;

    if (nbr < 0){
        my_putchar('-');
        nbr *= -1;
        l++;
    }
    if (nbr < 100000 && nbr > 0.00001)
        l += ifrounder(nbr, i, l, precision);
    else
        l += localscience(nbr, uporlow, l, precision);
    return l;
}
