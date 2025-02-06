/*
** EPITECH PROJECT, 2024
** maths
** File description:
** 101pong
*/

#include "my.h"
#include "coord.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int print_special(pong_t *ap)
{
    if ((ap->z1 - ap->z0) < 0 && ap->z0 < 0 || (ap->z1 - ap->z0) > 0
        && ap->z0 > 0 || (ap->z1 - ap->z0) == 0 && ap->z0 != 0){
        my_printf("The ball won't reach the paddle.\n");
        return 0;
    }
    if ((ap->z1 - ap->z0) == 0){
        my_printf("The incidence angle is:\n%.2f degrees\n", 0.00);
        return 0;
    }
    return 1;
}

int print_angle_coord(pong_t *ap)
{
    double time = 0;
    double nbr = 0;

    my_printf("(%.2f, %.2f, %.2f)\n", (ap->x1 + ap->n * (ap->x1 - ap->x0)),
        (ap->y1 + ap->n * (ap->y1 - ap->y0)),
        (ap->z1 + ap->n * (ap->z1 - ap->z0)));
    if (print_special(ap) == 0)
        return 0;
    time = (ap->z0 / (ap->z1 - ap->z0));
    if (time < 0)
        time *= -1;
    ap->x = time * (ap->x1 - ap->x0);
    ap->y = time * (ap->y1 - ap->y0);
    ap->z = time * (ap->z1 - ap->z0);
    ap->x = sqrtf(ap->x * ap->x + ap->y * ap->y + ap->z * ap->z);
    nbr = (asin(ap->z0 / ap->x) / (2 * 3.141592653579) * 360);
    if (nbr < 0)
        nbr *= -1;
    my_printf("The incidence angle is:\n%.2f degrees\n", nbr);
    return 0;
}

static int verif_letter(char *argv)
{
    for (int j = 0; argv[j] != '\0'; j++){
        if (argv[j] != '.' && argv[j] != '-' && argv[j] < '0' || argv[j] > '9')
            return 84;
    }
    return 0;
}

static pong_t *set_ap(char **argv, pong_t *ap)
{
    ap->x0 = my_getnbr(argv[1]);
    ap->y0 = my_getnbr(argv[2]);
    ap->z0 = my_getnbr(argv[3]);
    ap->x1 = my_getnbr(argv[4]);
    ap->y1 = my_getnbr(argv[5]);
    ap->z1 = my_getnbr(argv[6]);
    ap->n = my_getnbr(argv[7]);
    return ap;
}

int main(int argc, char **argv)
{
    pong_t *ap;

    ap = malloc(sizeof(pong_t));
    if (ap == NULL)
        return 84;
    if (argc != 8 || my_getnbr(argv[7]) < 0)
        return 84;
    for (int i = 1; argv[i] != NULL; i++)
        if (verif_letter(argv[i]) == 84)
            return 84;
    ap = set_ap(argv, ap);
    for (int i = 0; argv[7][i] != '\0'; i++)
        if (argv[7][i] == '.')
            return 84;
    my_putstr("The velocity vector of the ball is:\n(");
    my_printf("%.2f, %.2f, %.2f)\n", (ap->x1 - ap->x0),
        (ap->y1 - ap->y0), (ap->z1 - ap->z0));
    my_printf("At time t + %i, ball coordinates will be:\n", ap->n);
    print_angle_coord(ap);
    return 0;
}
