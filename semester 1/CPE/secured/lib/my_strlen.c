/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** conts nbr of caracter in str
*/

int my_strlen(char const *str)
{
    int a = 0;

    while (*str != '\0') {
        str++;
        a++;
    }
    return (a);
}
