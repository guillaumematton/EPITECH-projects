/*
** EPITECH PROJECT, 2024
** Task 02
** File description:
** reverse order
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    int c = 122;

    while (c > 96){
        my_putchar(c);
        c = c - 1;
    }
    return (0);
}
