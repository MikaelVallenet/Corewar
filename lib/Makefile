##
## EPITECH PROJECT, 2021
## Corewar
## File description:
## Lib Makefile
##

SRC	=	./sources/my_strlen.c	\
		./sources/my_putstr.c	\
		./sources/my_strcmp.c	\
		./sources/my_addchar.c	\
		./sources/my_convert_base.c	\
		./sources/my_getnbr.c	\
		./sources/my_strdup.c	\
		./sources/my_strcpy.c	\
		./sources/my_putchar.c	\
		./sources/my_putnbr.c	\
		./sources/my_getlongnbr.c \
		./sources/my_strcat.c \

CFLAGS	=	-I./includes/ -g3 -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all $(NAME) clean fclean re