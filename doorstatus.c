#include <stdio.h>
#include "systemfunctions.h"
#include <unistd.h>

void doorStatus(int stateOfLamp)
{
    switch(stateOfLamp)
    {
        case 0:
            printf("CURRENTLY LAMP IS: Off\n");
            break;

        case 1:            
            printf("CURRENTLY LAMP IS: ");
            greenColour();
            printf("Green\n");
            sleep(3);
            resetColour();
            break;
        
        default:
            
            printf("CURRENTLY LAMP IS: ");
            redColour();
            printf("Red\n");
            sleep(3);
            resetColour();
            break;
    }    
}