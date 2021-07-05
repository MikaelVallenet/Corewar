/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_strlen(char *str);
void my_putstr(char *str);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putstr, Full_string, .init=redirect_all_stdout)
{
    my_putstr("Bonjour moi c'est zork");
    cr_assert_stdout_eq_str("Bonjour moi c'est zork");
}

Test(my_putstr, Little_string, .init=redirect_all_stdout)
{
    my_putstr("Zorky");
    cr_assert_stdout_eq_str("Zorky");
}