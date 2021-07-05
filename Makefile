##
## EPITECH PROJECT, 2021
## Corewar
## File description:
## Global Makefile
##

COMPIL_GLOBAL	=	compil_global

all:	$(COMPIL_GLOBAL)

compil_lib:
	@echo " ====  LIB COMPILATION  ===="
	cd ./lib && make

compil_corewar:
	@echo " ==== COREWAR COMPILATION ===="
	cd ./corewar && make

compil_asm:
	@echo " ==== ASM COMPILATION ===="
	cd ./asm && make

$(COMPIL_GLOBAL):	compil_lib compil_corewar compil_asm

clean:
	cd ./corewar && make clean
	cd ./asm && make clean
	cd ./lib && make clean

fclean:
	cd ./corewar && make fclean
	cd ./asm && make fclean
	cd ./lib && make fclean
	find -name "unit-tests" -delete -o -name "*.gcno" -delete -o -name "*.gcda" -delete

re:	fclean all

tests_run:
	@echo " ==== TESTS COMPILATION ===="
	gcc -I./lib/includes -I./asm/includes -I./corewar/includes -g3 -Wall -Wextra -lcriterion --coverage -o unit-tests $(shell find -name "*.c" -not -path "./bonus/*" -not -name "main.c")
	./unit-tests

.PHONY:	all compil_lib compil_corewar $(COMPIL_GLOBAL) clean fclean re tests_run