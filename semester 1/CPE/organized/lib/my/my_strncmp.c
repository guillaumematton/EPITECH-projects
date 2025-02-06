/*
** EPITECH PROJECT, 2024
** my strncmp
** File description:
** strcmp function
*/

int condi(char const *s1, char const *s2, int i)
{
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

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int res = 0;
    int l1 = 0;
    int l2 = 0;

    for (; s1[l1] != '\0'; l1++);
    for (; s2[l2] != '\0'; l2++);
    if (n > l1 && n > l2){
        while (s1[i] == s2[i]){
            i++;
        }
        res = condi(s1, s2, i);
        return res;
    }
    while (s1[i] == s2[i] && i < n){
        i++;
    }
    res = condi(s1, s2, i);
    return res;
}
