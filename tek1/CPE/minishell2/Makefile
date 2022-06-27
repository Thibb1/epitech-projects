##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile template
##

#####################################################
#
# 					PARAMETERS
#
#####################################################
SOURCE	=	./main.c 						\
			./src/minishell.c				\
			./src/my_grep_str.c				\
			./src/command/shell.c			\
			./src/command/shell_run.c		\
			./src/command/shell_exec.c		\
			./src/command/parser.c			\
			./src/command/redirect.c		\
			./src/command/run_cmd_piped.c	\
			./src/list/env.c				\
			./src/list/str_list.c			\
			./src/str_to_arr.c				\
			./src/check.c					\
			./src/check_2.c					\
			./src/command/builtin.c			\
			./src/command/cd.c
OBJS	=	$(SOURCE:.c=.o)
OUT		=	mysh
CC		=	gcc
CFLAGS	+=	-W -Wall -Iincludes/
LFLAGS	=	-lmy
LDFLAGS	=	-Llib/my

#####################################################
#
# 					RULES
#
#####################################################
all: $(OUT)

$(OUT): $(OBJS)
	$(MAKE) -C lib/my/ all
	$(CC) $(OBJS) -o $(OUT) $(LFLAGS) $(LDFLAGS)

clean:
	$(MAKE) -C lib/my/ clean
	$(RM) $(OBJS) *~ *# *.o *.gc* src/*.gc* src/*.o *.out

fclean: clean
	$(MAKE) -C lib/my/ fclean
	$(RM) $(OUT)

re: fclean all

debug: CFLAGS += -ggdb3
debug: fclean $(OBJS)
	$(MAKE) -C lib/my/ debug
	$(CC) $(OBJS) -o $(OUT) $(LFLAGS) $(LDFLAGS)

.PHONY: all clean fclean re debug

#####################################################
#
# 					UNIT TEST RULES
#
#####################################################
unit_tests: all
	$(MAKE) -C tests/ all

unit_tests_page: all
	$(MAKE) -C tests/ html_page

unit_tests_fclean: fclean
	$(MAKE) -C tests/ fclean

.PHONY: unit_tests unit_tests_page unit_tests_fclean