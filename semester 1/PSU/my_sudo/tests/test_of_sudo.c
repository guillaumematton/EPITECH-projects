/*
** EPITECH PROJECT, 2025
** my-sudo
** File description:
** test_of_sudo
*/

#include "../include/my.h"
#include "../main.c"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(My_sudo, test_fonctionnel_1, .init = redirect_all_std)
{
	find_use();
    cr_assert(0);
}
Test(My_sudo, test_fonctionnel_2, .init = redirect_all_std)
{
	find_use();
    cr_assert(84);
}

Test(my_sudo, test_fonctionnel_3, .init = redirect_all_std)
{
    my_sudo();
    cr_assert_stdout_eq_str(84);
}
