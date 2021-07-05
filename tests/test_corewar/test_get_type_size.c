/*
** EPITECH PROJECT, 2021
** Test
** File description:
** test_get_type_size
*/

#include <criterion/criterion.h>
#include "cmd.h"

Test(get_type_size, reg_type)
{
    cr_assert_eq(T_REG, get_type_size(REG));
}

Test(get_type_size, dir2_type)
{
    cr_assert_eq(T_DIR2, get_type_size(DIR2));
}

Test(get_type_size, dir4_type)
{
    cr_assert_eq(T_DIR4, get_type_size(DIR4));
}

Test(get_type_size, ind_type)
{
    cr_assert_eq(T_IND, get_type_size(IND));
}

Test(get_type_size, no_type)
{
    cr_assert_eq(0, get_type_size(NO));
}