/*
** EPITECH PROJECT, 2024
** middle
** File description:
** the center of vstar
*/

void my_putchar(char c);
int vmtop(unsigned int size)
{
    int j = size;
    int i;
    int spaces = size * 6 - 3;
    int k;

    for (i = 1; i <= j; i++){
        for (k = 0; k < i; k++)
            my_putchar(32);
        my_putchar(42);
        for (k = 0; k < spaces; k++)
            my_putchar(32);
        my_putchar(42);
        my_putchar('\n');
        spaces -= 2;
    }
    return (spaces);
}

void vmbot(unsigned int size, int spaces)
{
    int i;
    int k;
    int j = size - 1;

    spaces += 2;
    for (i = 0; i < j; j--){
        spaces += 2;
        for (k = 0; k < j; k++)
            my_putchar(32);
        my_putchar(42);
        for (k = 0; k < spaces; k++)
            my_putchar(32);
        my_putchar(42);
        my_putchar('\n');
    }
}

void vbot(unsigned int size)
{
    int j = size * 2;
    int stop = size * 3 - 1;
    int spaces = 1 + 2 * (size - 2);
    int i;

    for (; j < stop; j++){
        for (i = 0; i <= j; i++)
            my_putchar(32);
        my_putchar(42);
        for (i = 0; i < spaces; i++)
            my_putchar(32);
        my_putchar(42);
        my_putchar('\n');
        spaces -= 2;
    }
    for (i = 0; i < size * 3; i++)
        my_putchar(32);
    my_putchar(42);
}
