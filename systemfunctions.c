#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

void clearInput();

/*
void hitEnter()
{
    clearInput();
    while (1) 
    {
        char pressEnter[1000];
        fgets(pressEnter, 1000, stdin);
        // scanf(" %s", pressEnter);
        if(strcmp(pressEnter,"") == 0 || strcmp(pressEnter,"") != 0)
        {
            break;
        }
    }
}
*/

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