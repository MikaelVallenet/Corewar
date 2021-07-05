/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** get_commands
*/

#include <stdlib.h>
#include "asm.h"
#include "parser.h"
#include "my.h"

static void sanitize_comments(char *str)
{
    for (; *str && *str != '\n' && *str != COMMENT_CHAR; str += 1);
    *str = 0;
}

static int check_label(head_t *head, char **buffer)
{
    int i = 0;
    char *label_name;

    skip_whitespaces(buffer);
    if (buffer[0][i] == '.')
        return (1);
    for (; buffer[0][i] && buffer[0][i] != '\n' && buffer[0][i] != LABEL_CHAR
    && buffer[0][i] != ' ' && buffer[0][i] != '\t'; i++);
    if (buffer[0][i] != LABEL_CHAR)
        return (0);
    label_name = my_strndup(*buffer, i);
    label_add_adresse(head->labels, label_name, head->buff_len);
    *buffer += i + 1;
    skip_whitespaces(buffer);
    return (0);
}

static int ascii_len(char *buffer)
{
    int i = 0;

    for (; *buffer && *buffer != ' ' && *buffer != '\t'
    && *buffer != SEPARATOR_CHAR; buffer++)
        i += 1;
    return (i);
}

static void check_commands(char **buffer, char **commands, int *i)
{
    int len = 0;

    for (; *i < 4 && **buffer; *i += 1) {
        len = ascii_len(*buffer);
        commands[*i] = my_strndup(*buffer, len);
        *buffer += len;
        skip_whitespaces(buffer);
        if (**buffer == SEPARATOR_CHAR && *i == 0)
            exit_error("Wrong commands format.");
        *buffer += (**buffer == SEPARATOR_CHAR);
        skip_whitespaces(buffer);
    }
}

char **parse_commands(head_t *head, char *buffer)
{
    char **commands;
    int i = 0;

    sanitize_comments(buffer);
    if (*buffer == 0 || check_label(head, &buffer))
        return (NULL);
    commands = malloc(sizeof(char *) * 5);
    check_commands(&buffer, commands, &i);
    commands[i] = NULL;
    if (*buffer != 0)
        exit_error("Wrong params format.");
    return (commands);
}