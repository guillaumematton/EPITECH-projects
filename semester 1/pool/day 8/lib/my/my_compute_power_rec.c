/*
** EPITECH PROJECT, 2024
** my compute power rec
** File description:
** same as task 3 but with rec
*/

int hardminmax(long a);

int my_pow(int nb, int p, int end_nb)
{
    end_nb *= nb;
    p--;
    if (end_nb > 2147483647)
        return 0;
    if (p > 0){
        my_pow(nb, p, end_nb);
    } else {
    return end_nb;
    }
}

int my_compute_power_rec(int nb, int p)
{
    long end_nb = 1;
    int c;

    if (p > 0){
        c = my_pow(nb, p, end_nb);
        return c;
    } else if (p == 0){
        return 1;
    } else {
        return 0;
    }
}
