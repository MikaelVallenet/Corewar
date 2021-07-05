/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** test_check_commands
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../asm/includes/asm.h"
#include "../../asm/src/parser/parser.h"

Test(parse_commands, parsing_commands)
{
    head_t head;
    char *buffer = my_strdup("      sti r1, %:live, %1\n");
    char **commands = parse_commands(&head, buffer);

    head.buff_len = 0;
    cr_assert_str_eq(commands[0], "sti");
    cr_assert_str_eq(commands[1], "r1");
    cr_assert_str_eq(commands[2], "%:live");
    cr_assert_str_eq(commands[3], "%1");
}
