/*
** EPITECH PROJECT, 2024
** digits
** File description:
** digits from 0 to 9
*/

void my_putchar(char c);

int my_print_digits(void)
{
    int c = 48;

    while (c < 58){
        my_putchar(c);
        c = c + 1;
    }
    return (0);
}
