/*
** EPITECH PROJECT, 2024
** main file
** File description:
** main file
*/

#include "include/my.h"
#include "stdio.h"

static int spanish(char letter, int percent, int span)
{
    if (letter == 'a' && percent >= 10 || letter == 'A' && percent >= 10)
        span++;
    if (letter == 'b' && percent >= 2 || letter == 'B' && percent >= 2)
        span++;
    if (letter == 'c' && percent >= 4 || letter == 'C' && percent >= 4)
        span++;
    if (letter == 'd' && percent >= 5 || letter == 'D' && percent >= 5)
        span++;
    if (letter == 'm' && percent >= 3 || letter == 'M' && percent >= 3)
        span++;
    if (letter == 'o' && percent >= 8 || letter == 'O' && percent >= 8)
        span++;
    if (letter == 'p' && percent >= 2 || letter == 'P' && percent >= 2)
        span++;
    if (letter == 's' && percent >= 8 || letter == 'S' && percent >= 8)
        span++;
    return span;
}

static int english(char letter, int percent, int eng)
{
    if (letter == 'f' && percent >= 2 || letter == 'F' && percent >= 2)
        eng++;
    if (letter == 'h' && percent >= 6 || letter == 'H' && percent >= 6)
        eng++;
    if (letter == 't' && percent >= 9 || letter == 'T' && percent >= 9)
        eng++;
    if (letter == 'w' && percent >= 2 || letter == 'W' && percent >= 2)
        eng++;
    if (letter == 'y' && percent >= 2 || letter == 'Y' && percent >= 2)
        eng++;
    return eng;
}

static int french(char letter, int percent, int fr)
{
    if (letter == 'i' && percent >= 7 || letter == 'I' && percent >= 7)
        fr++;
    if (letter == 'j' && percent >= 1 || letter == 'J' && percent >= 1)
        fr++;
    if (letter == 'l' && percent >= 5 || letter == 'L' && percent >= 5)
        fr++;
    if (letter == 'm' && percent >= 3 || letter == 'M' && percent >= 3)
        fr++;
    if (letter == 'p' && percent >= 2 || letter == 'P' && percent >= 2)
        fr++;
    if (letter == 'q' && percent >= 1 || letter == 'Q' && percent >= 1)
        fr++;
    if (letter == 's' && percent >= 8 || letter == 'S' && percent >= 8)
        fr++;
    if (letter == 'u' && percent >= 6 || letter == 'U' && percent >= 6)
        fr++;
    if (letter == 'v' && percent >= 2 || letter == 'V' && percent >= 2)
        fr++;
    return fr;
}

static int germ(char letter, int percent, int grm)
{
    if (letter == 'd' && percent >= 5 || letter == 'D' && percent >= 5)
        grm++;
    if (letter == 'e' && percent >= 16 || letter == 'E' && percent >= 16)
        grm++;
    if (letter == 'g' && percent >= 3 || letter == 'G' && percent >= 3)
        grm++;
    if (letter == 'k' && percent >= 1 || letter == 'K' && percent >= 1)
        grm++;
    if (letter == 'n' && percent >= 9 || letter == 'N' && percent >= 9)
        grm++;
    if (letter == 'r' && percent >= 7 || letter == 'R' && percent >= 7)
        grm++;
    if (letter == 'w' && percent >= 2 || letter == 'W' && percent >= 2)
        grm++;
    if (letter == 'z' && percent >= 1 || letter == 'Z' && percent >= 1)
        grm++;
    return grm;
}

int percentile(char **argv, int counter)
{
    int maxc = 0;
    int percent;

    for (int i = 0; argv[1][i] != '\0'; i++)
        if ('a' <= argv[1][i] && 'z' >= argv[1][i])
            maxc++;
        else if ('A' <= argv[1][i] && 'Z' >= argv[1][i])
            maxc++;
    percentileintegers(counter, maxc);
    percent = counter * 100 / maxc;
    return percent;
}

int lettercounter(char **argv, char letter)
{
    int counter = 0;

    for (int i = 0; argv[1][i] != '\0'; i++)
        if (argv[1][i] == letter)
            counter++;
    return counter;
}

static void last_line(int eng, int grm, int fr, int span)
{
    my_putstr("=> ");
    if (eng <= fr && grm <= fr && span <= fr)
        my_putstr("French ");
    if (eng <= grm && fr <= grm && span <= grm)
        my_putstr("German ");
    if (eng <= span && fr <= span && grm <= span)
        my_putstr("Spanish ");
    if (span <= eng && fr <= eng && grm <= eng)
        my_putstr("English ");
}

int subrush(char **argv, char letter)
{
    int counter = 0;
    int percent;
    int counter2;

    counter = lettercounter(argv, letter);
    if (letter <= 'Z' && 'A' <= letter)
        counter2 = lettercounter(argv, letter + 32);
    else if (letter <= 'z' && 'a' <= letter)
        counter2 = lettercounter(argv, letter - 32);
    my_putchar(letter);
    my_putchar(':');
    my_put_nbr(counter + counter2);
    percent = percentile(argv, counter + counter2);
    return percent;
}

int rush(char **argv)
{
    char letter;
    int percent;
    int grm = 0;
    int eng = 0;
    int fr = 0;
    int span = 0;

    if (argv[2] == NULL || argv[1] == NULL || argv[1][0] == '\0')
        return 84;
    for (int i = 2; argv[i] != NULL; i++){
        letter = argv[i][0];
        percent = subrush(argv, letter);
        eng = english(letter, percent, eng);
        grm = germ(letter, percent, grm);
        fr = french(letter, percent, fr);
        span = spanish(letter, percent, span);
        my_putchar('\n');
    }
    last_line(eng, grm, fr, span);
    return 0;
}

int main(int argc, char **argv)
{
    if (rush(argv) == 84){
        my_putstr("Error : invalid arguments\n");
        return 84;
    } else
        return 0;
}
