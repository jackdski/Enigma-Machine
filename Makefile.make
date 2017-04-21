CC = gcc
CFLAGS = -WALL -WEXTRA -std=c99 -pedantic -g 

PROG = main
SRC = main.c engima.c
HDR = enigma.h
OBJ = $(SRC:.c=.0)

$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
tags: $(SRC) $(HDR) 
	ctags $^
.PHONY: clean
clean: 
	$(RM) $(PROG) $(OBJ)
