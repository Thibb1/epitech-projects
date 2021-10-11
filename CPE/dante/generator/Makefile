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
SOURCE	=	./main.c	\
			./src/generator.c	\
			./src/check.c	\
			./src/generator_perfect.c	\
			./src/add_cluster.c \
			./src/generator_imperfect.c

OBJS	=	$(SOURCE:.c=.o)
OUT		=	generator
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
	$(RM) $(OBJS) *~ *# *.o *.gc* src/*.gc* src/*.o

fclean: clean
	$(MAKE) -C lib/my/ fclean
	$(RM) $(OUT)

re: fclean all

debug: fclean $(OBJS)
	$(MAKE) -C lib/my/ all
	$(CC) $(OBJS) -ggdb3 -o $(OUT) $(LFLAGS) $(LDFLAGS)

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