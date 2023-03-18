#include <stdio.h>
#include "systemfunctions.h"
#include <unistd.h>

void doorStatus(int stateOfLamp)
{
    printf("CURRENTLY LAMP IS: ");
    switch(stateOfLamp)
    {
        case 0:
            printf(" Off\n");
            break;

        case 1:
            greenColour();
            printf("Green\n");
            sleep(3);
            resetColour();
            break;
        
        default:
            redColour();
            printf("Red\n");
            sleep(3);
            resetColour();
            break;
    }    
}