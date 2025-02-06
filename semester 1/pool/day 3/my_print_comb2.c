/*
** EPITECH PROJECT, 2024
** comb 2
** File description:
** combination of digits
*/

void my_putchar(char c);

void lock_numbers(int a, int b, int c, int d)
{
    my_putchar(d + 48);
    my_putchar(c + 48);
    my_putchar(32);
    my_putchar(b + 48);
    my_putchar(a + 48);
    my_putchar(44);
    my_putchar(32);
}

int end_nb(void)
{
    my_putchar(57);
    my_putchar(56);
    my_putchar(32);
    my_putchar(57);
    my_putchar(57);
}

int sub_print_comb2(int a, int b, int c, int d)
{
    for (int i = 0; i < 9898; i++){
        a = a + 1;
        while (a > 9){
            a = 0;
            b = b + 1;
        }
        while (b > 9){
            b = 0;
            c = c + 1;
        }
        while (c > 9){
            c = 0;
            d = d + 1;
        }
        lock_numbers(a, b, c, d);
    }
}

int my_print_comb2(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    sub_print_comb2(a, b, c, d);
    end_nb();
    return (0);
}
