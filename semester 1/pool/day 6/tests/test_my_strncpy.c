/*
** EPITECH PROJECT, 2024
** test_my_strncpy.c
** File description:
** unit tests for my_strncpy.c
*/

#include <criterion/criterion.h>

Test(my_strncpy, copy_five_charaters)
{
    char dest[6] = {0};

    my_strncpy(dest, "helloworld", 5);
    cr_assert_str_eq(dest, "hello");
}
