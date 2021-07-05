/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>

char *my_strcat(char *dest, char *src);

Test(my_strcat, full_str)
{
    char *str = malloc(sizeof(char) * 9);

    str[0] = '\0';
    cr_assert_str_eq("Salut", my_strcat(str, "Salut"));
}

Test(my_strcat, Empty_add)
{
    char *str = malloc(sizeof(char) * 9);

    str[0] = 'a';
    str[1] = 'b';
    str[2] = '\0';

    cr_assert_str_eq("ab", my_strcat(str, ""));
}