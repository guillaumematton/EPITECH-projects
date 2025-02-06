/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** secured_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "../includes/hashtable.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Secured, test_fonctionnel_1, .init = redirect_all_std)
{
    printf("secured: %d\n", hash("secured", 7));
    cr_assert("secured: 563238");
}

Test(Secured, test_fonctionnel_2, .init = redirect_all_std)
{
    printf("secured: %d\n", hash("secured", 7));
    cr_assert(84);
}

Test(Secured, fonction_testing_simple_test, .init = redirect_all_std)
{
    hash("secured", 7);
    cr_assert("563238");
}

Test(Secured, foncction_testing_complexe_test, .init = redirect_all_std)
{
    hash("antidisestablishmentarianism", 7);
    cr_assert("8990990");
}
