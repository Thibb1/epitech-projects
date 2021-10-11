##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile template
##

###### PARAMETERS #####
SRC=$(shell find src/. -name '*.c')
BINARY=my_runner
OBJ=$(SRC:.c=.o)
CC=@gcc
AR=ar rc
CFLAGS+=-W -Wall -I./include -pedantic -ansi -std=gnu99
##### EXEC #####
all: $(BINARY)

$(BINARY): $(OBJ)
	@make -C lib/my all
	$(CC) $(OBJ) main.c -o $(BINARY) -Llib/my/ -lmy -Iinclude/ -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio

clean:
	@make -C lib/my clean
	@rm -f $(OBJ) main.o *~ *# unit_tests *.gcno *.gcna *.gcda coverage.info *.c.gcda *.c.gcov

fclean: clean
	@make -C lib/my fclean
	@rm -f $(BINARY)

re: fclean all

unit_tests: all
	@$(CC) $(OBJ) src/*.c lib/my/*.c tests/*.c -L./lib/my -lmy -o unit_tests -lcriterion -fprofile-arcs -ftest-coverage

run_tests: unit_tests
	@./unit_tests
	@gcov *.gcda
	@lcov -c --directory . --output-file coverage.info

output_tests: run_tests
	@genhtml coverage.info --output-directory ../output
	@make fclean

.PHONY: all clean fclean re
