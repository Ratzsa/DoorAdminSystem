#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void doorStatus(int stateOfLamp)
{
    switch(stateOfLamp)
    {
        case 0:
            printf("CURRENTLY LAMP IS: Off\n");
            break;

        case 1:
            printf("CURRENTLY LAMP IS: Green\n");
            sleep(3);
            break;
        
        default:
            printf("CURRENTLY LAMP IS: Red\n");
            sleep(3);
            break;
    }
    
}