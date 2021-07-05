/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** parser
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static void parse_prog_header(char *file, prog_t *prog, global_t *global)
{
    for (int i = 4; i < 4 + PROG_NAME_LENGTH; i++)
        prog->name[i - 4] = file[i];
    prog->name[PROG_NAME_LENGTH] = '\0';
    for (int i = 12 + PROG_NAME_LENGTH; i < 12 + PROG_NAME_LENGTH +
    COMMENT_LENGTH; i++)
        prog->comment[i - 12 - PROG_NAME_LENGTH] = file[i];
    prog->comment[COMMENT_LENGTH] = '\0';
    prog->size = file[4 + PROG_NAME_LENGTH];
    for (int i = 5 + PROG_NAME_LENGTH; i < 12 + PROG_NAME_LENGTH; i++) {
        prog->size = prog->size << 8;
        prog->size += file[i];
    }
    prog->color = give_color(global);
    prog->pc_print = -1;
}

static void verify_placing(global_t *global, prog_t *prog)
{
    if (prog->address == -1)
        return;
    if (!can_place_prog(global, prog, prog->address))
        show_error("Error: Bad program placement.\n");
}

static void define_content(char *file, prog_t *new)
{
    new->content = malloc(sizeof(char) * new->size);
    for (int i = 12 + PROG_NAME_LENGTH + COMMENT_LENGTH; i < 12 +
        PROG_NAME_LENGTH + COMMENT_LENGTH + new->size; i++)
        new->content[i - 12 - PROG_NAME_LENGTH - COMMENT_LENGTH] = file[i + 4];
}

/**
** Parse a core file content and create the champion
** @param char* File buffer content
** @param char* Text prog_nbr, NULL if not required
** @param char* Text load_address, NULL if not required
** @param global_t* Global structure
*/
void parse_cor_file(char *file, char *prog_nbr,
char *load_address, global_t *global)
{
    prog_t *new = malloc(sizeof(prog_t));

    new->id = (prog_nbr == NULL) ? get_first_valid_id(global)
        : my_getlongnbr(prog_nbr);
    if (!is_prog_id_valid(global, new->id))
        show_error("Error: Bad champion id.\n");
    new->address = (load_address == NULL) ? -1 : my_getnbr(load_address);
    new->carry = 0;
    new->live_call_cyle = 0;
    new->pc = 0;
    parse_prog_header(file, new, global);
    define_content(file, new);
    new->registers = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++)
        new->registers[i] = 0;
    new->registers[0] = new->id;
    new->last_execute = -1;
    verify_placing(global, new);
    add_prog(global, new);
}