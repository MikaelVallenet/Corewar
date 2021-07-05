/*
** EPITECH PROJECT, 2021
** Test
** File description:
** test_get_execute_address
*/

#include <criterion/criterion.h>
#include "cmd.h"

Test(select_address, basic_test)
{
    cr_assert_eq(21, select_address(21));
}

Test(select_address, overflow_value)
{
    cr_assert_eq(10, select_address(MEM_SIZE + 10));
}

Test(select_address, inv_overflow_value)
{
    cr_assert_eq(MEM_SIZE - 10, select_address(-10));
}