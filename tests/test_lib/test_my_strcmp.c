/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>

int my_strlen(char *str);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int n);

Test(my_strcmp, Equal)
{
    cr_assert_eq(0, my_strcmp("bonjour", "bonjour"));
}

Test(my_strcmp, Inferior)
{
    cr_assert_gt(0, my_strcmp("abcd", "abzz"));
}

Test(my_strcmp, Superior)
{
    cr_assert_lt(0, my_strcmp("abzz", "abcd"));
}