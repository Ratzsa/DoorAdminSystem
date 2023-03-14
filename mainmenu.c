#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "systemfunctions.h"
#include "doorstatus.h"
#include "cardmanagement.h"
#include "mainmenu.h"
#include "cardtest.h"

void mainMenu()
{
    CardStack number = {NULL, 0};
    int menuChoice;
    bool inMenu = true;

    while(inMenu)
    {
        clearConsole();
        printf("Admin menu\n");
        printf("1. Remote open door\n");
        printf("2. List all cards in system\n");
        printf("3. Add/remove access\n");
        printf("4. Exit\n");
        printf("9. FAKE TEST SCAN CARD\n");
        menuChoice = -1;
        scanf(" %d", &menuChoice);
        switch (menuChoice)
        {
            case 1:
                doorStatus(1);
                break;
            case 2:
                listCards(&number);
                break;
            case 3:
                cardManager(&number);
                break;
            case 4:
                printf("Exiting program.");
                inMenu = false;
                break;
            case 9:
                cardTest(&number);
                break;
            
            default:
                printf("Input error. Press enter to continue.");
                hitEnter();
                break;
        }
    }
}