/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>

int my_strlen(char *str);
char *my_addchar(char *str, char c, int position);
char *my_strcpy(char *str, char *dest);

Test(my_addchar, add_one_char_start)
{
    char *str = malloc(sizeof(char) * (5 + 1));

    my_strcpy("salut", str);
    cr_assert_str_eq("saluta", my_addchar(str, 'a', 0));
}

Test(my_addchar, add_char_at_the_end)
{
    char *str = malloc(sizeof(char) * (5 + 1));

    my_strcpy("salut", str);
    cr_assert_str_eq("zsalut", my_addchar(str, 'z', 1));
}