/*
** EPITECH PROJECT, 2021
** Test
** File description:
** test_exec_add
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "cmd.h"

static void define_values(global_t *global, prog_t *prog)
{
    global->memory = malloc(sizeof(int) * 10);
    global->memory[0] = 3;
    global->memory[1] = 84;
    global->memory[2] = 1;
    global->memory[3] = 4;
    global->memory[4] = 9;
    prog->registers = malloc(sizeof(int) * 16);
    prog->registers[0] = 3;
    prog->registers[3] = 27;
    prog->registers[8] = 0;
    prog->address = 0;
    prog->pc = 0;
}

Test(execute_add, basic_test)
{
    global_t global;
    prog_t prog;

    define_values(&global, &prog);
    execute_add(&global, &prog);
    cr_assert_eq(30, prog.registers[8]);
    cr_assert_eq(0, prog.carry);
    free(global.memory);
    free(prog.registers);
}

Test(execute_add, carry_test)
{
    global_t global;
    prog_t prog;

    define_values(&global, &prog);
    prog.registers[3] = -3;
    execute_add(&global, &prog);
    cr_assert_eq(0, prog.registers[8]);
    cr_assert_eq(1, prog.carry);
    free(global.memory);
    free(prog.registers);
}