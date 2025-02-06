/*
** EPITECH PROJECT, 2024
** test_my_strstr
** File description:
** unit test strstr
*/

#include <criterion/criterion.h>
char *my_strstr(char *str, char const *to_find);

Test(my_strstr, copy_five_characters_in_empty_array)
{
    char dest[50]  = "me and my friend";
    
    my_strstr(dest, "my");
    cr_assert_str_eq(dest, "");
}
