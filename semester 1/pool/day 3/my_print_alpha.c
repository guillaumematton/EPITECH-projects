/*
** EPITECH PROJECT, 2024
** my_print_alpha
** File description:
** main file
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    int c = 97;

    while (c < 123){
        my_putchar(c);
        c = c + 1;
    }
    return (0);
}
