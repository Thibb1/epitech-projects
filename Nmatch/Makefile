##
## EPITECH PROJECT, 2021
## Match Nmatch makefile
## File description:
## Makefile
##

SOURCE	=	./match.c				\
			./nmatch.c				\
			./tests/test_match.c	\
			./tests/test_nmatch.c
CC		=	gcc
OBJS	=	$(SOURCE:.c=.o)
OUT		=	unit_tests
CFLAGS	+=	-W -Wall -fprofile-arcs -ftest-coverage
LDLIBS 	=	-lcriterion

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(SOURCE) -o $(OUT) $(LDLIBS) $(LDFLAGS) $(CFLAGS)

.PHONY: all