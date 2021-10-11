##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makes files
##

#####################################################
#
# 					PARAMETERS
#
#####################################################
SOURCE	=	./my_atof.c		\
			./my_atoi.c		\
			./my_dprintf.c	\
			./my_ferror.c	\
			./my_flag.c		\
			./my_grep.c		\
			./my_maths.c	\
			./my_pfa.c		\
			./my_printf.c	\
			./my_putchar.c	\
			./my_putnbr.c	\
			./my_putstr.c	\
			./my_revstr.c	\
			./my_strcat.c	\
			./my_strcmp.c	\
			./my_strcpy.c	\
			./my_strdup.c	\
			./my_strlen.c	\
			./redirect_std.c
OBJS	=	$(SOURCE:.c=.o)
OUT		=	libmy.a
CC		=	gcc
CFLAGS	+=	-W -Wall -I../../includes/
AR		=	ar rc

#####################################################
#
# 					RULES
#
#####################################################
all: $(OUT)

$(OUT): $(OBJS)
	$(AR) $(OUT) $(OBJS)

clean:
	rm -f $(OBJS) *~ *# *.o *.gc*

fclean: clean
	rm -f $(OUT)

re: clean fclean all

debug: CFLAGS += -ggdb3
debug: re

.PHONY: all clean fclean re debug