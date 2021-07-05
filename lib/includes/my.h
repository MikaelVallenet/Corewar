/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** Header my
*/

#ifndef MY
#define MY

#define ABS(value) ((value > 0) ? (value) : (-(value)))

int my_strlen(char *str);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int n);
void my_putstr(char *str);
long my_getnbr(char *str);
char *my_convert_base(char *nbr, char *base_from, char *base_to);
char *my_addchar(char *str, char c, int position);
char *my_strdup(char *str);
char *my_strcpy(char *str, char *dest);
void my_putchar(char c);
void my_putnbr(int nb);
char *my_strncpy(char *str, char *dest, int len);
char *my_strndup(char *str, int len);
long my_getlongnbr(char const *str);
char *my_strcat(char *dest, char *src);

#endif /* !MY */