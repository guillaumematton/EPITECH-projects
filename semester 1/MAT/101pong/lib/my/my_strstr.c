/*
** EPITECH PROJECT, 2024
** my strstr
** File description:
** reproduce strstr
*/

int elsecond(char *str, char const *to_find, int loop)
{
    int i = 0;
    int n = 0;

    if (to_find[i] == str[loop]) {
        n = 0;
        while (to_find[i + n] != '\0' && to_find[i + n] == str[loop + n]) {
            n++;
        }
        if (to_find[i + n - 1] == str[loop + n - 1]) {
            return 1;
        }
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    if (to_find[0] == '\0'){
        return str;
    }
    for (int loop = 0; str[loop] != '\0'; loop++) {
        if (elsecond(str, to_find, loop) == 1) {
            return &str[loop];
        }
        if (elsecond(str, to_find, loop) == 0) {
            return "NULL";
        }
    }
}
