/*
** EPITECH PROJECT, 2024
** test strcapitalize
** File description:
** unit test
*/

#include <criterion/criterion.h>
char *my_strcapitalize(char *str);

Test(my_strcapitalize, first_letter_of_word_capitalized)
{
    char str[100] = "hello 4My-name is voId";

    my_strcapitalize(str);
    cr_assert_str_eq(str, "Hello 4my-Name Is Void");
}
