/*
** EPITECH PROJECT, 2024
** comb
** File description:
** all digits are different
*/


void my_putchar(char c);

void cycle(int a, int b, int c)
{
    if (b < c){
        my_putchar(a + 48);
        my_putchar(b + 48);
        my_putchar(c + 48);
        my_putchar(44);
        my_putchar(32);
    }
}

int last_number(void)
{
    my_putchar(55);
    my_putchar(56);
    my_putchar(57);
}

int my_print_comb(void)
{
    int a = 0;
    int b = 0;
    int c = 0;

    for (int i = 0; i < 789; i++) {
        if (a < b){
            cycle(a, b, c);
        }
        c = c + 1;
        while (c > 9){
            b = b + 1;
            c = 0;
        }
        while (b > 9){
            a = a + 1;
            b = 0;
        }
    }
    last_number();
    return (0);
}
