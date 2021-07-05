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

Test(my_strncmp, Equal)
{
    cr_assert_eq(0, my_strncmp("bonjour", "bonjour", 7));
}

Test(my_strncmp, Inferior)
{
    cr_assert_gt(0, my_strncmp("abcd", "abzz", 4));
}

Test(my_strncmp, Superior)
{
    cr_assert_lt(0, my_strncmp("abzz", "abcd", 4));
}