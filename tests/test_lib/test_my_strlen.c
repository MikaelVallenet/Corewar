/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>

int my_strlen(char *str);

Test(my_strlen, Empty_string)
{
    cr_assert_eq(0, my_strlen(""));
}

Test(my_strlen, Little_string)
{
    cr_assert_eq(3, my_strlen("hey"));
}

Test(my_strlen, Big_string)
{
    cr_assert_eq(31, my_strlen("yo tout le monde c'est squeezie"));
}