/*
** EPITECH PROJECT, 2024
** my str capitalize
** File description:
** capitalize first letter
*/

char *cond(char *str, int i)
{
    if (str[i - 1] == ' ' || str[i - 1] == '-' || str[i - 1] == '+'){
        if (str[i] < 'z' && str[i] > 'a'){
            str[i] -= 32;
        }
    }
    if (str[i] < 'Z' && str[i] > 'A'){
        str[i] += 32;
    }
    return str;
}

char *my_strcapitalize(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z'){
        str[0] -= 32;
        }
    for (int i = 0; str[i] != '\0'; i++){
        cond(str, i);
    }
}
