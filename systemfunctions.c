#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

void clearInput();

void hitEnter()
{
    clearInput();
    clearInput();
}

void clearConsole()
{
    printf("\x1b[H\x1b[2J\x1b[3J");
}

void clearInput()
{
    while(getchar() != '\n')
    {

    }
}