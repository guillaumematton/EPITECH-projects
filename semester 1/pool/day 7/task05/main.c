/*
** EPITECH PROJECT, 2024
** main
** File description:
** rev parameters
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
	my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    for (int i = argc; 0 < i; i--){
        my_putstr(argv[i - 1]);
        my_putchar('\n');
    }
}

