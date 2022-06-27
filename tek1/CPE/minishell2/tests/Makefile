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
SOURCE	=	./tests_atoi_atof.c		\
			./tests_maths.c			\
			./tests_my_printf.c		\
			./tests_str_cat.c		\
			./tests_str_cmp.c		\
			./tests_str_cmpn.c		\
			./tests_str_cpy.c		\
			../lib/my/my_atof.c		\
			../lib/my/my_atoi.c		\
			../lib/my/my_dprintf.c	\
			../lib/my/my_ferror.c	\
			../lib/my/my_flag.c		\
			../lib/my/my_grep.c		\
			../lib/my/my_maths.c	\
			../lib/my/my_pfa.c		\
			../lib/my/my_printf.c	\
			../lib/my/my_putchar.c	\
			../lib/my/my_putnbr.c	\
			../lib/my/my_revstr.c	\
			../lib/my/my_strcat.c	\
			../lib/my/my_strcmp.c	\
			../lib/my/my_strcpy.c	\
			../lib/my/my_strdup.c	\
			../lib/my/my_strlen.c	\
			../lib/my/redirect_std.c
OBJS	=	$(SOURCE:.c=.o)
OUT		=	../unit_tests
CC		=	gcc
CFLAGS	+=	-W -Wall -I../includes/ -fprofile-arcs -ftest-coverage
LDLIBS 	=	-lmy -lcriterion
LDFLAGS	=	-L../lib/my/

#####################################################
#
# 					RULES
#
#####################################################
all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(SOURCE) -o $(OUT) $(LDLIBS) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS) *.gc* coverage.info

fclean: clean
	$(RM) $(OUT)
	$(RM) -r ../output

re: fclean all

run: re
	./$(OUT)

html_page: run
	gcov *.gcda
	lcov -c --directory . --output-file coverage.info
	genhtml coverage.info --output-directory ../output

.PHONY: all clean fclean re run html_page