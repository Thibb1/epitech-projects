##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makes comp
##

SRC =$(wildcard *.c)

SRCOS =$(wildcard lib/my/*.o)

CC =gcc

AR =ar rc

CFLAGS =-W -Wall

TFLAGS =-lcriterion -fprofile-arcs -ftest-coverage

NAME =a.out

all: $(NAME)

$(NAME):
	@make -C lib/my
	@$(CC) $(SRC) $(CFLAGS) -Llib/my/ -lmy -Iinclude/ -o $(NAME)

clean:
	@rm -f $(NAME)

fclear:
	@rm lib/my/libmy.a $(SRCOS)

re: clean all

test:
	$(CC) $(SRC) $(CFLAGS) -Llib/my/ -lmy -Iinclude/ $(TFLAGS) tests/test_do_op.c
	@./a.out
	@gcov $(SRC)
	@lcov -c --directory . --output-file coverage.info
	@genhtml coverage.info --output-directory output
	@rm $(wildcard *.gcno) $(wildcard *.gcda) $(wildcard *.gcov) coverage.info
