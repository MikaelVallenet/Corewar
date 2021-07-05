/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
char *my_strdup(char *str);
char *my_strndup(char *str, int len);

Test(my_strdup, classical)
{
    char *str = "bonjour";

    cr_assert_str_eq("bonjour", my_strdup(str));
}

Test(my_strdup, nullptr)
{
    char *str = NULL;

    cr_assert_null(my_strdup(str));
}

Test(my_strndup, classical)
{
    char *str = "loveqdqs";

    cr_assert_str_eq("love", my_strndup(str, 4));
}

Test(my_strndup, nullptr)
{
    char *str = NULL;

    cr_assert_null(my_strndup(str, 5));
}