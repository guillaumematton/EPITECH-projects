/*
** EPITECH PROJECT, 2024
** vsize
** File description:
** variable star size
*/

void my_putchar(char c);
int vmtop(unsigned int size);
void vmbot(unsigned int size, int spaces);
void vbot(unsigned int size);

void vline(unsigned int size)
{
    int i;
    int j = size * 2 + 1;
    int hole = 1 + ((size - 1)*2);

    for (i = 0; i < j; i++)
        my_putchar(42);
    for (i = 0; i < hole; i++)
        my_putchar(32);
    for (i = 0; i < j; i++)
        my_putchar(42);
    my_putchar('\n');
}

void vtop(unsigned int size)
{
    int j = size * 3 - 1;
    int stop = size * 2;
    int spaces = 1;
    int i;

    for (i = 0; i < size * 3; i++)
        my_putchar(32);
    my_putchar(42);
    my_putchar('\n');
    for (; j > stop; j--){
        for (i = 0; i < j; i++)
            my_putchar(32);
        my_putchar(42);
        for (i = 0; i < spaces; i++)
            my_putchar(32);
        my_putchar(42);
        my_putchar('\n');
        spaces += 2;
    }
}

void vmiddle(unsigned int size)
{
    int spaces;

    spaces = vmtop(size);
    vmbot(size, spaces);
}

void vstar(unsigned int size)
{
    vtop(size);
    vline(size);
    vmiddle(size);
    vline(size);
    vbot(size);
}
