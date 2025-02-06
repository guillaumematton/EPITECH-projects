/*
** EPITECH PROJECT, 2024
** my compute square root
** File description:
** searching for square root
*/

int root(int nb, int c)
{
    int d = c * c;

    if (d < nb){
        c++;
        root(nb, c);
    } else if (d == nb) {
        return c;
    } else {
        return 0;
    }
}

int my_compute_square_root(int nb)
{
    int sqrt;
    int c = 0;

    if (nb >= 0){
        sqrt = root(nb, c);
        return sqrt;
    } else {
        return 0;
    }
}
