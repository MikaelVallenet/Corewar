##
## EPITECH PROJECT, 2021
## Corewar ASM
## File description:
## ASM Makefile
##

SRC	=	src/main.c							\
		src/file_writer.c 					\
		src/error_handler.c					\
		src/tools/file_tools.c				\
		src/tools/buff_tools.c				\
		src/loader/main_loader.c			\
		src/parser/main_parser.c			\
		src/parser/get_metadata.c			\
		src/parser/get_commands.c			\
		src/parser/check_commands.c			\
		src/parser/parse_command_args.c		\
		src/parser/parse_command_label.c	\
		src/parser/parser_tools.c			\
		src/label/get_label.c				\
		src/label/label_list_gest.c			\
		src/label/replace_labels.c			\
		src/parser/insert_prog_size.c		\
		src/parser/check_commands_aux.c		\
		src/label/label_add_pos.c			\
		src/parser/get_metadata_aux.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CFLAGS	=	-I./includes/ -I../lib/includes/ -L../lib/ -lmy -g3 -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all $(NAME) clean fclean re