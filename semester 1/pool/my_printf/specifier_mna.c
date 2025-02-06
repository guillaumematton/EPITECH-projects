/*
** EPITECH PROJECT, 2024
** rest of the specifier
** File description:
** a m n
*/

#include <stdlib.h>
#include "include/my.h"
#include <errno.h>

int percn(int *adress, int l)
{
    *adress = l;
    return 0;
}

int errfonct(int l, int err)
{
    if (err == 2){
        l += my_putstr("No such file or directory");
        return l;
    }
    if (err == 13){
        l += my_putstr("Permission denied");
        return l;
    } else {
        l += my_putstr("Success");
        return l;
    }
}

static int bintodec(int bina)
{
    int rang = 0;
    long nbrdec = 0;
    int len = my_nbrlength(bina);

    for (; len >= 0; len--){
        nbrdec += bina % 10 * my_compute_power_rec(2, rang);
        bina /= 10;
        rang++;
    }
    return nbrdec;
}

static char *followaconv(char *oconvert1, char *oconvert2,
    double toconvertemp, int itempo)
{
    int itemp = 0;
    int i = 0;

    for (; itempo >= 1; i++){
        oconvert1[i] = (itempo % 2) + 48;
        itempo /= 2;
    }
    itemp = i + 47;
    my_putchar(oconvert1[i - 1]);
    my_putchar('.');
    oconvert1 = my_revstr(oconvert1);
    for (; i <= itemp; i++){
        toconvertemp *= 2 + 48;
        itempo = toconvertemp;
        oconvert2[i] = itempo;
        toconvertemp -= itempo;
    }
    oconvert2 = my_revstr(oconvert2);
    my_strcat(oconvert1, oconvert2);
    return oconvert1;
}

int a_conv(double toconvert, int uporlow)
{
    int itempo = toconvert;
    long bina = 0;
    double toconvertemp = toconvert - itempo;
    char *oconvert1 = malloc(sizeof(char) * 999);
    char *oconvert2 = malloc(sizeof(char) * 999);

    bina = my_getnbr(followaconv(oconvert1, oconvert2, toconvertemp, itempo));
    while (my_nbrlength(bina) % 4 != 0){
        bina *= 10;
    }
    hexa(bintodec(bina), uporlow, 0);
    if (uporlow == 1)
        my_putchar('P');
    if (uporlow == 0)
        my_putchar('p');
    if (toconvert < 0)
        my_putchar('-');
    if (toconvert > 0)
        my_putchar('+');
    return 0;
}
