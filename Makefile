CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g 

PROG = main
SRC = main.c enigma.c
HDR = enigma.h
OBJ = $(SRC:.c=.o)

$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
tags: $(SRC) $(HDR) 
	ctags $^
.PHONY: clean
clean: 
	$(RM) $(PROG) $(OBJ)
