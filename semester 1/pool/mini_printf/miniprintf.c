/*
** EPITECH PROJECT, 2024
** miniprintf
** File description:
** main file for miniprintf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int checks(char *format, int i, va_list *list)
{
    if (format[i] == '%'){
        i++;
        if (format[i] == 's')
            my_putstr(va_arg(*list, char *));
        if (format[i] == 'i' || format[i] == 'd')
            my_put_nbr(va_arg(*list, int));
        if (format[i] == 'c')
            my_putchar(va_arg(*list, int));
        if (format[i] == '%')
            my_putchar('%');
        if (format[i] != 's' && format[i] != 'i' && format[i] != 'd'
            && format[i] != 'c' && format[i] != '%'){
            my_putchar('%');
            my_putchar(format[i]);
        }
    } else
        my_putchar(format[i]);
    return 0;
}

int nblength(va_list *list)
{
    int number = va_arg(*list, int);
    int length = 0;

    if (number == 0)
        return 1;
    while (number != 0){
        length++;
        number /= 10;
    }
    return length;
}

int flength(char *format, int i, va_list *list, int length)
{
    if (format[i] == '%'){
        i++;
        if (format[i] == 's')
            length += my_strlen(va_arg(*list, char *));
        if (format[i] == 'i' || format[i] == 'd')
            length += nblength(&list);
        if (format[i] == 'c')
            length++;
            va_arg(*list, int);
        if (format[i] == '%')
            length++;
        if (format[i] != 's' && format[i] != 'i' && format[i] != 'd'
            && format[i] != 'c' && format[i] != '%')
            length += 2;
    } else
        length++;
    return length;
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int length = 0;
    int nb = 3;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++){
        checks((char *)format, i, &list);
        if (format[i] == '%')
            i++;
    }
    va_end(list);
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++){
        length = flength((char *)format, i, &list, length);
        if (format[i] == '%')
            i++;
    }
    va_end(list);
    return length;
}
