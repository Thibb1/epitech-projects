
##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile template
##

#####################################################
#
# 					PARAMETERS
#
#####################################################
SOURCE	=	./DoOp.hs
OUT		=	doop
CC		=	ghc
CFLAGS	+=	-W -Wall

#####################################################
#
# 					RULES
#
#####################################################
all: $(OUT)

$(OUT):
	$(CC) -o $(OUT) --make $(SOURCE) $(CFLAGS)

clean:
	$(RM) $(OBJS) *~ *# *.o *.gc* src/*.gc* src/*.o *.hi

fclean: clean
	$(RM) $(OUT)

re: fclean all

.PHONY: all clean fclean re