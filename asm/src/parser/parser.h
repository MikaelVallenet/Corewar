/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_


/* PROTOTYPE */
void parse_metadata(head_t *head);
char **parse_commands(head_t *head, char *buffer);
void skip_whitespaces(char **buffer);
void place_size_bytes(head_t *head);
int pars_all_metadata(head_t *head, char *str);
int pars_metadata(head_t *head, char *str, int *i, int *name);

#endif /* !PARSER_H_ */
