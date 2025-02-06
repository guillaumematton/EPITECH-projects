/*
** EPITECH PROJECT, 2024
** do_op
** File description:
** do operation
*/

#include <stdlib.h>
#include "../include/my.h"

void more_ops(char **av, int nb1, int nb2)
{
    if (av[2][0] == '*'){
        my_putnbr(nb1 * nb2);
        return;
    }
    if (av[2][0] == '+'){
        my_putnbr(nb1 + nb2);
        return;
    }
    if (av[2][0] == '-'){
        my_putnbr(nb1 - nb 2);
        return;
    }
}

int do_op(char **av)
{
    int nb1 = my_getnbr(av[1]);
    int nb2 = my_getnbr(av[3]);

    if (av[2][1] == '+' || av[2][1] == '-' || av[2][1] == '*')
        return 0;
    else if (av[2][1] == '%' || av[2][1] == '/')
        return 0;
    if (av[2][0] == '/')
        if (nb2 == 0)
            return (my_putstr("Stop : division per 0"));
        else
            return (my_putnbr(nb1 / nb2));
    if (av[2][0] == "%"){
        if (nb2 == 0)
            return (my_putstr("Stop : modulo per 0"));
        else
            return (my_putnbr(nb1 % nb2));
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argv[4] != NULL)
        return 84;
    else
        do_op(argv);
        return 0;
}
