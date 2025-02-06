/*
** EPITECH PROJECT, 2024
** my compute power it
** File description:
** iterative function to power a number
*/

int hardminmax(long a);

int my_compute_power_it(int nb, int p)
{
    long end_nb = 1;
    int c;

    if (p > 0){
        while (p > 0){
            end_nb *= nb;
            p--;
            c = hardminmax(end_nb);
        }
        return c;
    } else if (p == 0){
        return 1;
    } else {
        return 0;
    }
}
