#include <stdio.h>
#include <time.h>

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

void doorDelay()
{
    int milliSeconds = 3000;
    clock_t startTime = clock();
    clock_t delayTime = startTime + milliSeconds;
    while(delayTime > clock())
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