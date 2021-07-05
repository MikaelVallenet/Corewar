/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_putchar(char c);
void redirect_all_stdout(void);

Test(my_putchar, letter, .init=redirect_all_stdout)
{
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}

Test(my_putchar, digit, .init=redirect_all_stdout)
{
    my_putchar('1');
    cr_assert_stdout_eq_str("1");
}