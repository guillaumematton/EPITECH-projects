/*
** EPITECH PROJECT, 2024
** strncmp
** File description:
** same as before but until n
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int ans;
    int s1l;
    int s2l;

    for (s1l = 0; s1[s1l] != '\0'; s1l++);
    for (s2l = 0; s2[s2l] != '\0'; s2l++);
    if (s1l < s2l)
        s1l = s2l;
    if (n > s1l)
        n = s1l;
    while (i < n){
        if (s1[i] == s2[i])
            i++;
    }
    if (s1[i] < s2[i])
        return -1;
    if (s2[i] < s1[i])
        return 1;
    return 0;
}
