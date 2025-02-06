/*
** EPITECH PROJECT, 2024
** test strncmp
** File description:
** unit test for my_strncmp
*/

#include <criterion/criterion.h>
int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, compare_until_n)
{
    int k;
    
    k = my_strncmp("hello", "hello", 6);
    cr_assert_eq(k, 0);
}
