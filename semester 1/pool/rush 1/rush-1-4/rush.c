/*
** EPITECH PROJECT, 2024
** rush-1-2
** File description:
** rush 1 assignement 2
*/

void my_putchar(char c);
void other(int x, int y);

void whx1(int y)
{
    int i;

    for (i = 0; i < y; i++){
        my_putchar(66);
        my_putchar('\n');
    }
}

void why1(int x)
{
    int i;

    for (i = 0; i < x; i++){
        my_putchar(66);
    }
}

void arr(int x, int y)
{
    if (y == 1 && x == 1){
        my_putchar(66);
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
