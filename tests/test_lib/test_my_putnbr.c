/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_putnbr(int nb);
void my_putchar(char c);
void redirect_all_stdout(void);

Test(my_putnbr, nbr_positif, .init=redirect_all_stdout)
{
    my_putnbr(8045);
    cr_assert_stdout_eq_str("8045");
}

Test(my_putnbr, nbr_negatif, .init=redirect_all_stdout)
{
    my_putnbr(-8045);
    cr_assert_stdout_eq_str("-8045");
}

Test(my_putnbr, nbr_0, .init=redirect_all_stdout)
{
    my_putnbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_putnbr, nbr_max, .init=redirect_all_stdout)
{
    my_putnbr(-2147483648);
    cr_assert_stdout_eq_str("-2147483648");
}