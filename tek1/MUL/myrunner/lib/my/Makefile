##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makes files
##

###### PARAMETERS #####
SRC=$(wildcard *.c)
BINARY=libmy.a
OBJ=$(SRC:.c=.o)
CFLAGS+=-W -Wall -pedantic -ansi -std=gnu99
CC=gcc
AR=ar rc

##### EXEC #####
all: $(BINARY)

$(BINARY): $(OBJ)
	@$(AR) $(BINARY) $(OBJ)

clean:
	@rm -f $(OBJ) *~ *#

fclean: clean
	@rm -f $(BINARY)

re: clean fclean all

.PHONY: all clean fclean re
