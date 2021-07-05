##
## EPITECH PROJECT, 2021
## Corewar
## File description:
## Corewar Makefile
##

SRC	=	./sources/main.c	\
		./sources/error_handler.c	\
		./sources/arguments/args_manager.c	\
		./sources/arguments/dump_arg.c	\
		./sources/arguments/load_address_arg.c	\
		./sources/arguments/prog_number_arg.c	\
		./sources/parser/file_checker.c	\
		./sources/parser/parser.c	\
		./sources/cycle_loop.c	\
		./sources/game_end.c	\
		./sources/programs/progs_manager.c	\
		./sources/programs/progs_sorter.c	\
		./sources/programs/progs_tools.c	\
		./sources/programs/progs_placer.c	\
		./sources/commands/cmd_executor.c	\
		./sources/commands/cmd_tools.c	\
		./sources/commands/cmd_checker.c	\
		./sources/executors/exec_live.c	\
		./sources/commands/cmd_utils.c	\
		./sources/commands/cmd_utils_aux.c \
		./sources/executors/exec_and.c	\
		./sources/executors/exec_sti.c	\
		./sources/executors/exec_zjmp.c	\
		./sources/commands/cmd_writer.c	\
		./sources/executors/exec_or.c	\
		./sources/executors/exec_aff.c	\
		./sources/executors/exec_fork.c	\
		./sources/executors/exec_lfork.c	\
		./sources/executors/exec_xor.c \
		./sources/executors/exec_ld.c	\
		./sources/executors/exec_st.c	\
		./sources/executors/exec_ldi.c	\
		./sources/executors/exec_lldi.c	\
		./sources/executors/exec_add.c	\
		./sources/executors/exec_sub.c	\
		./sources/executors/exec_lld.c	\
		./sources/programs/prog_tester.c

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CFLAGS	=	-I./includes/ -I../lib/includes/ -L../lib/ -lmy -g3 -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all $(NAME) clean fclean re
