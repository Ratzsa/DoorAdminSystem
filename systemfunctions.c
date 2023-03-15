#include <stdio.h>
#include <stdlib.h>

void clearInput();
void redColour();
void resetColour();
void greenColour();

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

void redColour() 
{
    printf("\033[1;31m");
}

void resetColour() 
{
    printf("\033[0m");
}

void greenColour()
{
    printf("\033[0;32m");
}