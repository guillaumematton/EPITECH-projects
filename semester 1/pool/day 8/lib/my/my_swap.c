/*
** EPITECH PROJECT, 2024
** my swap
** File description:
** invert a and b location
*/
void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
