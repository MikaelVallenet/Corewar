/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** my_addchar
*/

#include <stdlib.h>

int my_strlen(char *str);

/**
* /!\ str Need to be allocated
* @param char* Allocated str
* @param char Char to be added
* @param int 0 start, 1 end
*/
char *my_addchar(char *str, char c, int position)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    if (position) {
        result[0] = c;
        for (; str[i] != '\0'; i++)
            result[i + 1] = str[i];
    } else {
        result[my_strlen(str)] = c;
        for (; str[i] != '\0'; i++)
            result[i] = str[i];
        i += 1;
    }
    result[i + 1] = '\0';
    free(str);
    return (result);
}