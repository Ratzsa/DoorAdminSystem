#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void openDoor(int stateOfLamp)
{
    switch(stateOfLamp)
    {
        case 0:
            printf("CURRENTLY LAMP IS: Off\n");
            fflush(stdin);
            sleep(3);
            break;

        case 1:
            printf("CURRENTLY LAMP IS: Green\n");
            fflush(stdin);
            sleep(3);
            break;
        
        default:
            printf("CURRENTLY LAMP IS: Red\n");
            fflush(stdin);
            sleep(3);
            break;
    }
    
}