PROG=main.exe
CC=gcc
CFLAGS=-g -Wall -Werror
DEPS = mainmenu.h doorstatus.h systemfunctions.h cardmanagement.h cardtest.h
OBJ = main.o mainmenu.o doorstatus.o systemfunctions.o cardmanagement.o cardtest.o
 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
 
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)