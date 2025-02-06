/*
** EPITECH PROJECT, 2024
** my compute square root
** File description:
** returns the square root
*/

int inr(int a, int b, int nb)
{
    int c;

    a++;
    b++;
    c = a * b;
    if (c < nb){
        inr(a, b, nb);
    } else if (c == nb){
        return a;
    } else {
        return 0;
    }
}

int my_compute_square_root(int nb)
{
    int a = 0;
    int b = 0;

    if (nb < 0){
        return 0;
    }
    a = inr(a, b, nb);
    return a;
}
