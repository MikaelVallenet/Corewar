/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
int my_getnbr(char *str);
int my_strlen(char *str);

Test(my_getnbr, empty_str)
{
    cr_assert_eq(0, my_getnbr(""));
}

Test(my_getnbr, digit)
{
    cr_assert_eq(3, my_getnbr("3"));
}

Test(my_getnbr, negativ_nbr)
{
    cr_assert_eq(-73, my_getnbr("-73"));
}