/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
char *my_strcpy(char *str, char *dest);
char *my_strncpy(char *str, char *dest, int len);
int my_strlen(char *str);

Test(my_strcpy, classical)
{
    char *dest = malloc(8);

    my_strcpy("bonjour", dest);
    cr_assert_str_eq("bonjour", dest);
}

Test(my_strcpy, emptyline)
{
    char *dest = malloc(sizeof(char));

    my_strcpy("", dest);
    cr_assert_str_eq("", dest);
}

Test(my_strncpy, classical)
{
    char *str = "loveqdqs";
    char *dest = malloc(4);

    my_strncpy(str, dest, 4);
    cr_assert_str_eq("love", dest);
}