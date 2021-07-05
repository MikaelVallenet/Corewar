/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char *src)
{
    int i;

    for (i = 0; dest[i] != '\0'; i += 1);
    for (int j = 0; src[j] != '\0'; dest[i] = src[j], i += 1, j += 1);
    dest[i] = '\0';
    return (dest);
}