##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile template
##

###### PARAMETERS #####
#SRC=$(wildcard src/*.c)
SRC=$(shell find src/. -name '*.c')
BINARY=my_defender
OBJ=$(SRC:.c=.o)
CC=gcc
AR=ar rc
CFLAGS+=-W -Wall -I./includes
CSFML+= -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

##### EXEC #####
all: $(BINARY)

$(BINARY): $(OBJ)
	@make -s -C lib/my all
	@$(CC) main.c $(OBJ) -Llib/my/ -lmy -Iincludes/ -o $(BINARY) -lm $(CSFML)

valgrind:
	@$(CC) main.c $(SRC) -g -Llib/my/ -lmy -Iincludes/ -o $(BINARY) -lm $(CSFML)

clean:
	@make -s -C lib/my clean
	@rm -f $(OBJ) *~ *# unit-tests
	@rm -f *.gcno *.gcna *.gcda coverage.info *.c.gcda *.c.gcov vgcore*

fclean: clean
	@make -s -C lib/my fclean
	@rm -f $(BINARY)

re: fclean all

unit_tests: all
	@$(CC) $(OBJ) lib/my/*.c tests/*.c -L./lib/my -lmy -o unit-tests -lcriterion -fprofile-arcs -ftest-coverage

tests_run: unit_tests
	@./unit-tests

output_tests: tests_run
	@gcov *.gcda
	@lcov -c --directory . --output-file coverage.info
	@genhtml coverage.info --output-directory ../output
	@make fclean

.PHONY: all clean fclean re
