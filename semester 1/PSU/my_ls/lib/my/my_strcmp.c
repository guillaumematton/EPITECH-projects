/*
** EPITECH PROJECT, 2024
** my strcmp
** File description:
** strcmp fonction
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int res = 0;

    while (s1[i] == s2[i]){
        i++;
    }
    if (s1[i] < s2[i]){
        return -1;
    }
    if (s1[i] > s2[i]){
        return 1;
    }
    if (s1[i] == s2[i]){
        return 0;
    }
}
