/*
** EPITECH PROJECT, 2024
** my compute factorial
** File description:
** return factorial
*/

int hardminmax(long a)
{
    int w;

    if (a < -2147483648 || a > 2147483647){
        return 0;
    } else {
        w = (int)a;
        return w;
    }
}

int my_compute_factorial_it(int nb)
{
    long end_number = 1;
    int c;

    if (nb > 0){
        while (nb > 0){
            end_number *= nb;
            nb--;
        }
        c = hardminmax(end_number);
        return c;
    } else if (nb == 0){
        return 1;
    } else {
        return 0;
    }
}
