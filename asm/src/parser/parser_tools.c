/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** parser_tools
*/

void skip_whitespaces(char **buffer)
{
    for (; (**buffer && **buffer != '\n') &&
    (**buffer == '\t' || **buffer == ' '); *buffer += 1);
}