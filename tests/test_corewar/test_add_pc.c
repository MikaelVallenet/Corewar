/*
** EPITECH PROJECT, 2021
** Test
** File description:
** test_get_execute_address
*/

#include <criterion/criterion.h>
#include "cmd.h"

Test(add_pc, basic_test)
{
    int pc = 2;

    add_pc(&pc, 19);
    cr_assert_eq(21, pc);
}

Test(add_pc, overflow_value)
{
    int pc = 70000;

    add_pc(&pc, 100);
    cr_assert_eq(4564, pc);
}

Test(add_pc, inv_overflow_value)
{
    int pc = 0;

    add_pc(&pc, -50);
    cr_assert_eq(65486, pc);
}