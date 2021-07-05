/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
char *my_convert_base(char *nbr, char *base_from, char *base_to);
int my_strlen(char *str);
int my_strcmp(char *str1, char *str2);
char *my_addchar(char *str, char c, int position);

Test(my_convert_base, same_base)
{
    cr_assert_str_eq("15", my_convert_base("15", "012345689", "012345689"));
}

Test(my_convert_base, dectohex)
{
    cr_assert_str_eq("14",
    my_convert_base("E", "012345689ABCDEF", "012345689"));
}

Test(my_convert_base, dectobin)
{
    cr_assert_str_eq("1110", my_convert_base("15", "012345689", "01"));
}

Test(my_convert_base, bintohex)
{
    cr_assert_str_eq("B", my_convert_base("1010", "01", "012345689ABCDEF"));
}

Test(my_convert_base, bintodec)
{
    cr_assert_str_eq("14", my_convert_base("1101", "01", "012345689"));
}
