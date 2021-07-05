/*
** EPITECH PROJECT, 2021
** Test
** File description:
** test_exec_and
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "cmd.h"

static void define_values(global_t *global, prog_t *prog)
{
    global->memory = malloc(sizeof(int) * 1000);
    global->memory[0] = 6;
    global->memory[1] = 228;
    global->memory[2] = 0;
    global->memory[3] = 21;
    global->memory[4] = 0;
    global->memory[5] = 0;
    global->memory[6] = 0;
    global->memory[7] = 32;
    global->memory[8] = 11;
    prog->registers = malloc(sizeof(int) * 16);
    global->memory[21] = 0;
    global->memory[22] = 0;
    global->memory[23] = 0;
    global->memory[24] = 2;
    prog->address = 0;
    prog->pc = 0;
}

Test(execute_and, basic_test)
{
    global_t global;
    prog_t prog;

    define_values(&global, &prog);
    execute_and(&global, &prog);
    cr_assert_eq(2 & 32, prog.registers[10]);
    cr_assert_eq(((2 & 32) == 0), prog.carry);
    free(global.memory);
    free(prog.registers);
}