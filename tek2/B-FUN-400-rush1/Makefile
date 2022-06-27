##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SOURCE	=	./pushswap_checker.hs
OUT		=	pushswap_checker
CC		=	ghc
CFLAGS	+=	-W -Wall -O2

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(SOURCE) -o $(OUT) $(CFLAGS)

clean:
	$(RM) *.o *.hi

fclean: clean
	$(RM) $(OUT)

re: fclean all