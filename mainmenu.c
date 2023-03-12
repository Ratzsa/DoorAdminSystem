#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "systemfunctions.h"
#include "opendoor.h"
#include "cardmanagement.h"
#include "mainmenu.h"

void mainMenu()
{
    CardStack number = {NULL, 0};
    int menuChoice;
    bool inMenu = true;

    while(inMenu)
    {
        clearConsole();
        fflush(stdin);
        printf("Admin menu\n");
        printf("1. Remote open door\n");
        printf("2. List all cards in system\n");
        printf("3. Add/remove access\n");
        printf("4. Exit\n");
        printf("9. FAKE TEST SCAN CARD\n");

        scanf(" %5d", &menuChoice);

        switch (menuChoice)
        {
            case 1:
                openDoor(1);
                break;
            case 2:
                listCards(&number);
                break;
            case 3:
                cardManager(&number);
                break;
            case 4:
                printf("Exiting program\n");
                inMenu = false;
                break;
            case 9:
                printf("Menu choice 9\n");
                hitEnter();
                break;
            
            default:
                printf("Input error.\n");
                hitEnter();
                break;
        }
    }
}