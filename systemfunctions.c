#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

void clearInput();

void hitEnter()
{
    clearInput();
    while (1) 
    {
        char pressEnter[1000];
        gets(pressEnter);
        if(strcmp(pressEnter,"") == 0 || strcmp(pressEnter,"") != 0)
        {
        // sleep(1);
        break;
        }
    }
    return;
}

void clearConsole()
{
    printf("\x1b[H\x1b[2J\x1b[3J");
}

void clearInput()
{    
    while(getchar() != '\n');
}