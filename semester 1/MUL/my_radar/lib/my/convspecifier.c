/*
** EPITECH PROJECT, 2024
** all function after %
** File description:
** function
*/

#include <stdlib.h>
#include "../../include/my.h"

int lastcondition(const char *format, int i, int l)
{
    if (format[i] != 'd' && format[i] != 'i'
        && format[i] != 's' && format[i] != 'c'
        && format[i] != '%' && format[i] != 'o'
        && format[i] != 'u' && format[i] != 'x'
        && format[i] != 'X' && format[i] != 'e'
        && format[i] != 'E' && format[i] != 'f'
        && format[i] != 'F' && format[i] != 'g'
        && format[i] != 'G' && format[i] != 'a'
        && format[i] != 'A' && format[i] != 'p'
        && format[i] != 'n' && format[i] != 'm'){
        my_putchar('%');
        i++;
    }
    l += 2;
    return i;
}

static int flagcheck(const char *format, char **type, int itemp, va_list *ap)
{
    for (int j = 0; j < 5; j++)
        if (type[0][j] == format[itemp]){
            switch_case_flag_1(j, ap);
            itemp++;
        }
    if (format[itemp] == '-'){
        switch_case_flag_1(2, ap);
        itemp++;
    }
    return itemp;
}

static int length_and_conv_check(const char *format, char **type,
    int itemp, va_list *ap)
{
    int precision = -1;

    if (format[itemp] == '.'){
        itemp++;
        precision = 0;
        for (; '0' <= format[itemp] && '9' >= format[itemp]; itemp++){
            precision *= 10;
            precision += (format[itemp] - 48);
        }
    }
    for (int j = 0; j < 10; j++)
        if (type[1][j] == format[itemp]){
            switch_case_length_1(j, ap);
            itemp++;
        }
    for (int j = 0; j < 20; j++){
        if (type[2][j] == format[itemp])
            switch_case_conv_1(j, ap, precision);
    }
    return itemp;
}

static int set_width(const char *format, int itemp)
{
    int width = 0;

    width *= 10;
    width += (format[itemp] - 48);
    return width;
}

static char **set_type(void)
{
    char **type;

    type = malloc(sizeof(char *) * 3);
    type[0] = malloc(sizeof(char) * 6);
    type[0] = "#0- +";
    type[1] = malloc(sizeof(char) * 10);
    type[1] = "hhllqLjzZt";
    type[2] = malloc(sizeof(char) * 25);
    type[2] = "disc%oxXuFfGgEeaAnmp";
    return type;
}

int functionafterperc(const char *format, int i, va_list *ap, int l)
{
    int width = 0;
    int itemp = i + 1;
    char **type;

    type = set_type();
    itemp = flagcheck(format, type, itemp, ap);
    for (; '0' <= format[itemp] && '9' >= format[itemp]; itemp++)
        width = set_width(format, itemp);
    itemp = length_and_conv_check(format, type, itemp, ap);
    itemp = lastcondition(format, itemp, l);
    return itemp;
}
