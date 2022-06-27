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
BINARY	=	dante

#####################################################
#
# 					RULES
#
#####################################################
all: $(BINARY)

$(BINARY): $(OBJ)
	$(MAKE) -C solver all
	$(MAKE) -C generator all

clean:
	$(MAKE) -C solver clean
	$(MAKE) -C generator clean

fclean: clean
	$(MAKE) -C solver fclean
	$(MAKE) -C generator fclean

re: fclean all

debug:
	$(MAKE) -C solver debug
	$(MAKE) -C generator debug

.PHONY: all clean fclean re debug