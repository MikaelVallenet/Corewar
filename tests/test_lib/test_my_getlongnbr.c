/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
long my_getlongnbr(char const *str);

Test(my_getlongnbr, empty_str)
{
    cr_assert_eq(0, my_getlongnbr(""));
}

Test(my_getlongnbr, digit)
{
    cr_assert_eq(3, my_getlongnbr("3"));
}

Test(my_getlongnbr, negativ_nbr)
{
    cr_assert_eq(-73, my_getlongnbr("--+-+73"));
}