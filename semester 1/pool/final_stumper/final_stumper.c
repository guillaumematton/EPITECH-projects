/*
** EPITECH PROJECT, 2024
** final stumper
** File description:
** detect squares of rush1
*/

#include "include/my.h"

static int test_for_rush_1_4_and_1_5(char *square)
{
    int test = 0;
    int i = 0;

    for (; square[i] != '\0'; i++);
    i -= 2;
    if (square[i] == 'C')
        test = square4_analysis(square);
    if (square[i] == 'A')
        test = square5_analysis(square);
    return test;
}

static int last_test(char *square, int test, int i)
{
    i -= 1;
    if (square[i] == 'A'){
        test = square3_analysis(square);
    }
    if (square[i] == 'C')
        test = test_for_rush_1_4_and_1_5(square);
    return test;
}

static int more_tests(char *square, int test)
{
    int i = 0;

    if (square[0] == 'B' && square[1] == '\n' && square[2] == '\0'){
        my_putstr("[rush1-3] 1 1 || [rush1-4] 1 1 || [rush1-5] 1 1\n");
        test = 1;
    }
    if (square[0] == 'o' && test == 0){
        test = square1_analysis(square);
    }
    if (square[0] == '/' && test == 0)
        test = square2_analysis(square);
    if (square[0] == 'A' && test == 0){
        for (; square[i] != '\n'; i++);
        test = last_test(square, test, i);
    }
    if (test == 0){
        my_putstr("none\n");
        return 84;
    } else
        return 1;
}

int final_stumper(char *square)
{
    int test = 0;

    if (square[0] == 'o' && square[1] == '\n' && square[2] == '\0'){
        my_putstr("[rush1-1] 1 1\n");
        test = 1;
    }
    if (square[0] == '*' && square[1] == '\n' && square[2] == '\0'){
        my_putstr("[rush1-2] 1 1\n");
        test = 1;
    }
    test = more_tests(square, test);
    return test;
}
