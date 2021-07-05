/*
** EPITECH PROJECT, 2021
** Test
** File description:
** test_get_execute_address
*/

#include <criterion/criterion.h>
#include "cmd.h"

Test(get_execute_address, basic_test)
{
    prog_t prog = {"a", "b", 4, 0, 0, 0, 137, 0, NULL, NULL, 0};

    cr_assert_eq(141, get_execute_address(&prog));
}

Test(get_execute_address, overflow_test)
{
    prog_t prog = {"a", "b", MEM_SIZE, 0, 0, 0, 144, 0, NULL, NULL, 0};

    cr_assert_eq(144, get_execute_address(&prog));
}