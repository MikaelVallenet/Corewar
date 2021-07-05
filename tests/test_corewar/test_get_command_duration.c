/*
** EPITECH PROJECT, 2021
** Test
** File description:
** test_get_execute_address
*/

#include <criterion/criterion.h>
#include "cmd.h"

Test(get_command_duration, basic_test)
{
    cr_assert_eq(20, get_command_duration(9));
    cr_assert_eq(50, get_command_duration(14));
}

Test(get_execute_address, invalid_cmd)
{
    cr_assert_eq(-1, get_command_duration(27));
}