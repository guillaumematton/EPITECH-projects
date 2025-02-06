/*
** EPITECH PROJECT, 2024
** my strcmp
** File description:
** strcmp fonction
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != '\0'; i++);
    return s1[i] - s2[i];
}
