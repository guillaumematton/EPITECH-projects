/*
** EPITECH PROJECT, 2024
** other.c
** File description:
** other function
*/

void my_putchar(char c);

void first_line(int x, int y)
{
    int i;

    my_putchar(47);
    for (i = 2; i < x; i++)
        my_putchar(42);
    my_putchar(92);
}

void end_line(int x, int y)
{
    int i;

    my_putchar(92);
    for (i = 2; i < x; i++)
        my_putchar(42);
    my_putchar(47);
}

void other(int x, int y)
{
    int i;
    int k;
    int spaces = x - 2;

    first_line(x, y);
    my_putchar('\n');
    for (i = 2; i < y; i++){
        my_putchar(42);
    for (k = 0; k < spaces; k++)
            my_putchar(32);
        my_putchar(42);
        my_putchar('\n');
    }
    end_line(x, y);
}
