/*
** EPITECH PROJECT, 2025
** lib
** File description:
** find_alphanum
*/

int find_alphanum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    if ('A' <= str[i] && str[i] <= 'Z' || 'a' <= str[i] && str[i] <= 'z' ||
        '0' <= str[i] && str[i] <= '9')
        return 1;
    return 0;
}
