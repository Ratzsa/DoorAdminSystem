#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

void hitEnter()
{
    fflush(stdin);
    while (1) 
    {
        char pressEnter[1000];
        gets(pressEnter);
        if(strcmp(pressEnter,"") == 0 || strcmp(pressEnter,"") != 0)
        {
        Sleep(100);
        break;
        }
    }
    // fflush(stdin);
    return;
}

void clearConsole()
{
    printf("\x1b[H\x1b[2J\x1b[3J");
}