/*
** EPITECH PROJECT, 2024
** my_starcapitalize
** File description:
** make every letter lower but the first of each word
*/

char high(char *str, int i)
{
    if ('a' <= str[i] && str[i] <= 'z')
        str[i] -= 32;
    return str[i];
}

char low(char *str, int i)
{
    if ('A' <= str[i] && str[i] <= 'Z')
                str[i] += 32;
    return str[i];
}

char *my_strcapitalize(char *str)
{
    int i;
    int length = 0;

    for (i = 0; str[i] != '\0'; i++)
        length++;
    if ('a' <= str[0] && str[0] <= 'z')
        str[0] -= 32;
    for (i = 0; i < length; i++){
        if (str[i] == ' ' || str[i] == '+' || str[i] == '-'){
            i++;
            str[i] = high(str, i);
        } else {
            str[i] = low(str, i);
        }
    }
    return str;
}
