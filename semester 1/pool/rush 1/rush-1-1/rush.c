/*
** EPITECH PROJECT, 2024
** rush-1-1
** File description:
** first assignement
*/

void my_putchar(char c);

void whx1(int y)
{
    int i;

    my_putchar(111);
    my_putchar('\n');
    for (i = 2; i < y; i++){
        my_putchar(124);
        my_putchar('\n');
    }
    my_putchar(111);
}

void why1(int x)
{
    int i;

    my_putchar(111);
    for (i = 2; i < x; i++){
        my_putchar(45);
    }
    my_putchar(111);
}

void other(int x, int y)
{
    int i;
    int k;
    int spaces = x - 2;

    why1(x);
    my_putchar('\n');
    for (i = 2; i < y; i++){
        my_putchar(124);
        for (k = 0; k < spaces; k++)
            my_putchar(32);
        my_putchar(124);
        my_putchar('\n');
    }
    why1(x);
}

void arr(int x, int y)
{
    if (y == 1 && x == 1){
        my_putchar(111);
        return;
    }
    if (x == 1){
        whx1(y);
        return;
    }
    if (y == 1){
        why1(x);
        return;
    }
    other(x, y);
    return;
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0 || (x % 1) != 0 || (y % 1) != 0){
        my_putchar("Invalid size\n");
        return;
    } else
        arr(x, y);
}
