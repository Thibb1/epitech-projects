##
## EPITECH PROJECT , 2020
## Makefile
## File description :
## makes compilation steps
##

SRC =$(wildcard *.c)

CC =gcc

AR =ar rc

CFLAGS =-W -Wall

LDFLAGS =-Lmy/lib -Iinclude

OBJ =$(SRC:.c=.o)

NAME =libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@cp $(NAME) ../
	@cp include/my.h ../../include/my.h

clean:
	@rm $(wildcard *.o)

fclean:
	@rm ../../include/my.h  ../$(NAME) $(NAME)

re: clean fclean all
