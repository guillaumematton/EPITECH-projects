/*
** EPITECH PROJECT, 2024
** my star
** File description:
** draw a star
*/

void my_putchar(char c);
void vstar(unsigned int size);

void line1(void)
{
    int i;

    for (i = 0; i < 3; i++){
        my_putchar(42);
    }
    my_putchar(32);
    for (i = 0; i < 3; i++){
        my_putchar(42);
    }
    my_putchar('\n');
}

void center1(void)
{
    my_putchar(32);
    my_putchar(42);
    my_putchar(32);
    my_putchar(32);
    my_putchar(32);
    my_putchar(42);
    my_putchar('\n');
}

void bottom1(void)
{
    int i;

    for (i = 0; i < 3; i++)
        my_putchar(32);
    my_putchar(42);
}

void star1(void)
{
    int i;

    for (i = 0; i < 3; i++){
        my_putchar(32);
    }
    my_putchar(42);
    my_putchar('\n');
    line1();
    center1();
    line1();
    bottom1();
}

void star(unsigned int size)
{
    if (size == 1)
        star1();
    if (size > 1)
        vstar(size);
    else
        return;
}
