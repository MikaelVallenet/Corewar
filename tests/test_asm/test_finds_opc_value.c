/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_parse_commands
*/

#include <criterion/criterion.h>
#include "../../asm/includes/asm.h"

Test(finds_opc_value, reg)
{
    cr_assert_eq(2, finds_opc_value(1, 1, 2));
}

Test(finds_opc_value, dir4)
{
    cr_assert_eq(1, finds_opc_value(4, 1, 2));
}

Test(finds_opc_value, dir2)
{
    cr_assert_eq(1, finds_opc_value(2, 1, 2));
}

Test(finds_opc_value, ind)
{
    cr_assert_eq(3, finds_opc_value(3, 1, 2));
}

Test(finds_opc_value, other)
{
    cr_assert_eq(0, finds_opc_value(15, 1, 2));
}