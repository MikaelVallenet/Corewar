/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <cmd.h>

static global_t gen_global(void)
{
    global_t global = {-1, 0, CYCLE_TO_DIE, NULL, NULL, -1, 0, NULL};

    global.memory = malloc(sizeof(int) * 10);
    global.memory[0] = 6;
    global.memory[1] = 228;
    global.memory[2] = 0;
    global.memory[3] = 21;
    global.memory[4] = 0;
    global.memory[5] = 0;
    global.memory[6] = 0;
    global.memory[7] = 32;
    global.memory[8] = 11;
    return (global);
}

Test(check_cmd, valid_cmd)
{
    global_t global = gen_global();

    cr_assert_eq(1, check_cmd(&global, 0));
}

Test(check_cmd, invalid_arg_types)
{
    global_t global = gen_global();

    global.memory[1] = 236;
    cr_assert_eq(0, check_cmd(&global, 0));
}

Test(check_cmd, invalid_reg_nbr)
{
    global_t global = gen_global();

    global.memory[8] = 19;
    cr_assert_eq(0, check_cmd(&global, 0));
}