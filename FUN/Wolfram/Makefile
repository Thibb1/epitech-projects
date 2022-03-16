##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

OUT	= wolfram

all: $(OUT)

$(OUT):
	stack install --local-bin-path .
	mv wolfram-exe wolfram

clean:
	stack clean

fclean: clean
	$(RM) $(OUT)
	stack purge

re: fclean all