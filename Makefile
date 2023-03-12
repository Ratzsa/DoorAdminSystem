PROG=main.exe
CC=gcc
CFLAGS=-g -Wall -Werror
DEPS = mainmenu.h opendoor.h systemfunctions.h cardmanagement.h
OBJ = main.o mainmenu.o opendoor.o systemfunctions.o cardmanagement.o
 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
 
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)