/*
** EPITECH PROJECT, 2024
** switchcase
** File description:
** switchcase cover
*/

#include "../../include/my.h"
#include <stdarg.h>
#include <errno.h>

static int switch_case_conv_4(int tabvalue, va_list *ap, int l, int precision)
{
    switch (tabvalue){
    case 15:
        my_putstr("0x");
        a_conv(va_arg(*ap, double), 0);
        return l;
    case 16:
        my_putstr("0X");
        a_conv(va_arg(*ap, double), 1);
        return l;
    case 17:
        percn(va_arg(*ap, int *), l);
        return l;
    case 18:
        l += errfonct(l, errno);
        return l;
    case 19:
        l += my_putstr("0x");
        l += pconv(va_arg(*ap, void *), 0);
        return l;
    }
}

static int switch_case_conv_3(int tabvalue, va_list *ap, int l, int precision)
{
    switch (tabvalue){
    case 10:
        l += rounder(va_arg(*ap, double), 0, precision);
        return l;
    case 11:
        l += mixscirou(va_arg(*ap, double), 1, precision);
        return l;
    case 12:
        l += mixscirou(va_arg(*ap, double), 0, precision);
        return l;
    case 13:
        l += science(va_arg(*ap, double), 1, precision);
        return l;
    case 14:
        l += science(va_arg(*ap, double), 0, precision);
        return l;
    default:
        l += switch_case_conv_4(tabvalue, ap, l, precision);
        return l;
    }
}

static int switch_case_conv_2(int tabvalue, va_list *ap, int l, int precision)
{
    switch (tabvalue){
    case 5:
        l += octal(va_arg(*ap, unsigned int), precision);
        return l;
    case 6:
        l += hexa(va_arg(*ap, unsigned int), 0, precision);
        return l;
    case 7:
        l += hexa(va_arg(*ap, unsigned int), 1, precision);
        return l;
    case 8:
        l += decimale(va_arg(*ap, unsigned int), precision);
        return l;
    case 9:
        l += rounder(va_arg(*ap, double), 0, precision);
        return l;
    default:
        l += switch_case_conv_3(tabvalue, ap, l, precision);
        return l;
    }
}

int switch_case_conv_1temp(int tabvalue, va_list *ap, int l, int precision)
{
    switch (tabvalue){
    case 3:
        my_putchar(va_arg(*ap, int));
        l++;
        return l;
    case 4:
        my_putchar('%');
        l++;
        return l;
    default:
        l += switch_case_conv_2(tabvalue, ap, l, precision);
        return l;
    }
    return l;
}

int switch_case_conv_1(int tabvalue, va_list *ap, int precision)
{
    int l = 0;

    switch (tabvalue){
    case 0:
        l += case1(va_arg(*ap, int), precision);
        return l;
    case 1:
        l += case1(va_arg(*ap, int), precision);
        return l;
    case 2:
        l += case2(va_arg(*ap, char *), precision);
        return l;
    default:
        l += switch_case_conv_1temp(tabvalue, ap, l, precision);
        return l;
    }
}
