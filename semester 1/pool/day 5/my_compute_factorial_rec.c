/*
** EPITECH PROJECT, 2024
** my compute factorial rec
** File description:
** recursive of task 1
*/

int hardminmax(long a);

int pos_fact(int nb, int end_number)
{
    end_number *= nb;
    nb--;
    if (end_number > 2147483647)
        return 0;
    if (nb > 0){
        pos_fact(nb, end_number);
    } else {
        return end_number;
    }
}

int my_compute_factorial_rec(int nb)
{
    long end_number = 1;
    int c;

    if (nb > 0){
        c = pos_fact(nb, end_number);
        return c;
    } else if (nb == 0){
        return 1;
    } else {
        return 0;
    }
}
