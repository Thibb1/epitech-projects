##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makes files
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

clean:
	@rm $(wildcard *.o)

fclean:
	@rm $(NAME)

re: clean fclean all
