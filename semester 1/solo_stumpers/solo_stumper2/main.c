/*
** EPITECH PROJECT, 2025
** countwords
** File description:
** main file
*/

#include <unistd.h>

int check_if_non_alpha(char **argv, int i)
{
    int j = 0;

    if (argv[1][i] <= 'A' || 'Z' <= argv[1][i] &&
        argv[1][i] <= 'a' || 'z' <= argv[1][i]){
        for (; argv[2][j] != '\0' && argv[2][j] != argv[1][i]; j++);
        if (argv[2][j] != argv[1][i])
            return 84;
    }
    return 0;
}

int check_for_character(char **argv, int i)
{
    int j = 0;

    if ('a' <= argv[1][i] && argv[1][i] <= 'z'){
        for (; argv[2][j] != '\0' && argv[2][j] != argv[1][i]
            && (argv[2][j] + 32) != argv[1][i]; j++);
        if (argv[2][j] != argv[1][i] && (argv[2][j] + 32) != argv[1][i])
            return 84;
    }
    if ('A' <= argv[1][i] && argv[1][i] <= 'Z'){
        for (; argv[2][j] != '\0' && argv[2][j] != argv[1][i]
            && (argv[2][j] - 32) != argv[1][i]; j++);
        if (argv[2][j] != argv[1][i] && (argv[2][j] - 32) != argv[1][i])
            return 84;
    }
    if (check_if_non_alpha(argv, i) == 84)
        return 84;
    return 0;
}

int check_for_ascii(char **argv)
{
    int combined_value1 = 1;
    int combined_value2 = 1;

    for (int i = 0; argv[1][i] != '\0'; i++){
        if ('A' <= argv[1][i] && argv[1][i] <= 'Z')
            combined_value1 *= (argv[1][i] + 32);
        else
            combined_value1 *= argv[1][i];
    }
    for (int i = 0; argv[2][i] != '\0'; i++){
        if ('A' <= argv[2][i] && argv[2][i] <= 'Z')
            combined_value2 *= (argv[2][i] + 32);
        else
            combined_value2 *= argv[2][i];
    }
    if (combined_value1 != combined_value2){
        write(1, "no anagrams.\n", 14);
        return 84;
    }
    return 0;
}

void error_output(int argc)
{
    if (argc < 3)
        write(2, "Error: not enough arguments.\n", 29);
    else
        write(2, "Error: too many arguments.\n", 27);
    return;
}

int main(int argc, char **argv)
{
    int len_1 = 0;

    if (argc != 3){
        error_output(argc);
        return 84;
    }
    for (; argv[1][len_1] != '\0'; len_1++);
    if (argv[2][len_1] != '\0'){
        write(1, "no anagrams.\n", 14);
        return 0;
    }
    for (int i = 0; argv[1][i] != '\0'; i++){
        if (check_for_character(argv, i) == 84){
            write(1, "no anagrams.\n", 14);
            return 0;
        }
    }
    if (check_for_ascii(argv) != 84)
        write(1, "anagram!\n", 10);
    return 0;
}
