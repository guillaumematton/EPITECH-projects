/*
** EPITECH PROJECT, 2024
** my compute square root
** File description:
** returns the square root
*/

double inr(double a, double b, double nb)
{
    double c;

    a += 0.001;
    b += 0.001;
    c = a * b;
    if (c < nb){
        inr(a, b, nb);
    } else if (c >= nb){
        return a;
    } else {
        return 0;
    }
}

double my_compute_square_root(double nb)
{
    double a = 0;
    double b = 0;

    if (nb < 0){
        return 0;
    }
    a = inr(a, b, nb);
    return a;
}
