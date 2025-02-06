/*
** EPITECH PROJECT, 2024
** power
** File description:
** power in rec
*/

long rec(long a, int nb, int p)
{
    p--;
    if (p > 0){
        a *= nb;
        rec(a, nb, p);
    } else {
        return a;
    }
}

int overflow(long k)
{
    int h = 1;

    if (k < -2147483648 || k > 2147483647){
        h = 0;
    }
    return h;
}

double pneg(int nb, int p)
{
    double fakenb = nb;

    for (; p <= 0; p++){
        fakenb /= 10;
    }
    return fakenb;
}

double my_compute_power_rec(int nb, int p)
{
    long a = nb;
    int h;
    double k;

    if (p < 0){
        k = pneg(nb, p);
        return k;
    }
    if (p == 0){
        return 1;
    }
    k = rec(a, nb, p);
    h = overflow(k);
    k *= h;
    return k;
}
