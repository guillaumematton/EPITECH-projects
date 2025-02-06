/*
** EPITECH PROJECT, 2024
** miniprintf
** File description:
** miniprintf
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdarg.h>

int lookforp(const char *format, int i, va_list *ap, int g)
{
    if (format[i] != '%'){
        my_putchar(format[i]);
    } else {
        i = functionafterperc(format, i, ap, g);
    }
    return i;
}

int my_printf(const char *format, ...)
{
    int g = 0;
    int comptabiliseur = 0;
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++){
        i = lookforp(format, i, &ap, g);
        g++;
    }
    va_end(ap);
    return comptabiliseur - 1;
}
