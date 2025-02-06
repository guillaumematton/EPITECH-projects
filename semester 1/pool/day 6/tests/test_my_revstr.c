/*
** EPITECH PROJECT, 2024
** test_my_revstr.c
** File description:
** coverage for my_revstr
*/

#include <criterion/criterion.h>
char *my_revstr(char *str);

Test(my_revstr, reverse_string)
{
    char str[6] = "hello";
    
    my_revstr(str);
    cr_assert_str_eq(str, "olleh");
}
