/*
** EPITECH PROJECT, 2024
** strstr
** File description:
** return string after substring
*/

int sec_fonc(char *str, int i, char const *to_find)
{
    int k = 0;
    int l = 0;
    int j = i;
    int s = 0;

    for (; str[j] != '\0'; j++)
        s++;
    for (; to_find[l] != '\0'; l++);
    while (str[i] == to_find[k]){
        k++;
        i++;
    }
    if (k == l)
        return s;
    return 0;
}

char *newstr(char *str, int i, int s)
{
    int j = 0;
    char *newstr;

    while (str[i] != '\0'){
        newstr[j] = str[i];
        j++;
        i++;
    }
    newstr[j] = '\0';
    return newstr;
}

char *my_strstr(char *str, char const *to_find)
{
    int s;
    int i = 0;

    if (to_find[0] == '\0')
        return str;
    while (str[i] != '\0'){
        s = sec_fonc(str, i, to_find);
        if (s != 0){
            str = newstr(str, i, s);
            return str;
        }
        i++;
    }
    return 0;
}
