/*
** EPITECH PROJECT, 2024
** complementary function
** File description:
** to help with switchcase
*/

#include "include/my.h"
#include <stdlib.h>

int octal(unsigned int toconvert, int precision)
{
    char *oconvert = malloc(sizeof(char) * 15);

    for (int i = 0; toconvert != 0; i++){
        oconvert[i] = toconvert % 8 + 48;
        toconvert -= toconvert % 8;
        toconvert /= 8;
    }
    for (int j = my_strlen(oconvert); j < precision; j++)
        my_putchar('0');
    my_putstr(my_revstr(oconvert));
    return my_strlen(oconvert);
}

int hexa(unsigned int toconvert, int uporlow, int precision)
{
    char *oconvert = malloc(sizeof(char) * 15);

    for (int i = 0; toconvert != 0; i++){
        if (toconvert % 16 < 10)
            oconvert[i] = toconvert % 16 + 48;
        if (uporlow == 0 && toconvert % 16 >= 10)
            oconvert[i] = toconvert % 16 + 87;
        if (uporlow == 1 && toconvert % 16 >= 10)
            oconvert[i] = toconvert % 16 + 55;
        toconvert -= toconvert % 16;
        toconvert /= 16;
    }
    for (int j = my_strlen(oconvert); j < precision; j++)
        my_putchar('0');
    my_putstr(my_revstr(oconvert));
    return my_strlen(oconvert);
}

int decimale(unsigned int toconvert, int precision)
{
    char *oconvert = malloc(sizeof(char) * 15);

    for (int i = 0; toconvert != 0; i++){
        oconvert[i] = toconvert % 10 + 48;
        toconvert -= toconvert % 10;
        toconvert /= 10;
    }
    for (int j = my_strlen(oconvert); j < precision; j++)
        my_putchar('0');
    my_putstr(my_revstr(oconvert));
    return my_strlen(oconvert);
}

static int print_rounder(int precision)
{
    my_putchar('1');
    if (precision > 0){
        my_putchar('.');
        for (int i = 1; i <= precision; i++)
            my_putchar('0');
    }
    return (precision + 2);
}

static int following_of_rounder(double nbr, int precision, int valin,
    int yesornoscience)
{
    int nbrtemp = nbr;
    int l = 0;

    if (nbr >= my_compute_power_rec(10, precision)){
        if (yesornoscience == 1)
            return print_rounder(precision);
        valin++;
        nbrtemp = 0;
        nbr = 0;
    }
    l += my_put_nbr(valin);
    my_putchar('.');
    l++;
    for (int i = 1; i < precision; i++){
        nbrtemp /= 10;
        if (nbrtemp < 1)
            my_putchar('0');
    }
    l += my_put_nbr((int)nbr);
    return l;
}

int rounder(double nbr, int yesornoscience, int precision)
{
    int l = 0;
    long valin = nbr;
    long doubleint = 0;

    if (precision < 0)
        precision = 6;
    nbr -= valin;
    if (nbr < 0)
        nbr *= -1;
    for (int i = 0; i <= precision; i++){
        nbr *= 10;
    }
    doubleint = nbr;
    if (doubleint % 10 >= 5){
        nbr /= 10;
        nbr += 1;
    } else
        nbr /= 10;
    l += following_of_rounder(nbr, precision, valin, yesornoscience);
    return l;
}

static int following_of_science(int pui, int l)
{
    if (pui >= 0)
        my_putchar('+');
    else {
        pui *= -1;
        my_putchar('-');
    }
    l++;
    if (pui < 10)
        my_putchar('0');
    l++;
    l += my_put_nbr(pui);
    return l;
}

int science(double nbr, int uporlow, int precision)
{
    int pui = 0;
    int l = 0;

    if (precision < 0)
        precision = 6;
    for (; nbr < 1; pui--){
        nbr *= 10;
        l = 1;
    }
    for (; nbr >= 10; pui++)
        nbr /= 10;
    if ((nbr + my_compute_power_rec(10, -precision)) >= 10)
        pui++;
    l += rounder(nbr, 1, precision);
    if (uporlow == 1)
        my_putchar('E');
    else
        my_putchar('e');
    l += (following_of_science(pui, l) + 1);
    return l;
}
