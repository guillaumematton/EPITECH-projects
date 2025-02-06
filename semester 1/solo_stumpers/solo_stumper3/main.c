/*
** EPITECH PROJECT, 2025
** fozzbazz
** File description:
** main file
*/

#include <stdio.h>
#include <stdlib.h>

void print_result(int temp_nb)
{
    if ((temp_nb % 2) == 0 && (temp_nb % 9) == 0){
        printf("FozzBazz\n");
        return;
    }
    if ((temp_nb % 2) == 0){
        printf("Fozz\n");
        return;
    }
    if ((temp_nb % 9) == 0){
        printf("Bazz\n");
        return;
    }
    if ((temp_nb % 2) != 0 && (temp_nb % 9) != 0){
        printf("%d\n", temp_nb);
        return;
    }
}

int check_for_errors(int argc, char **argv)
{
    int i = 0;

    if (argc != 3)
        return 84;
    if (argv[1][0] == '-')
        i = 1;
    for (; argv[1][i] != '\0'; i++)
        if ('0' > argv[1][i] || argv[1][i] > '9')
            return 84;
    if (i == 1 && argv[1][0] == '-' || i == 0)
        return 84;
    i = 0;
    if (argv[2][0] == '-')
        i = 1;
    for (; argv[2][i] != '\0'; i++)
        if ('0' > argv[2][i] || argv[2][i] > '9')
            return 84;
    if (i == 1 && argv[2][0] == '-' || i == 0)
        return 84;
    return 0;
}

int main(int argc, char **argv)
{
    int start = 0;
    int end = 0;
    int temp_nb = 0;

    if (check_for_errors(argc, argv) == 84)
        return 84;
    start = atoi(argv[1]);
    end = atoi(argv[2]);
    if (start > end)
        return 84;
    for (temp_nb = start; temp_nb <= end; temp_nb++)
        print_result(temp_nb);
    return 0;
}
