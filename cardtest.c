#include <stdio.h>
#include <stdbool.h>
#include "doorstatus.h"
#include <string.h>
#include <ctype.h>
#include "systemfunctions.h"
#include <stdlib.h>
#include "cardmanagement.h"

int checkInput(char inputText[]);

void cardTest()
{
    char input[20];
    bool scanningCard = true;
    int goodInput;
    Card cardSearch;

    while(scanningCard)
    {
        clearConsole();
        printf("Please scan card to enter or X to go back to admin mode.\n");
        doorStatus(0);
        scanf(" %10s", input);
        goodInput = checkInput(input);

        switch(goodInput)
        {
            case 1:
                scanningCard = false;
                break;

            case 2:
                cardSearch = findCardInFile(atoi(input));
                if(cardSearch.cardNumber >= 0)
                {
                    doorStatus(cardSearch.access);
                }
                else
                {
                    printf("Card not in system. ");
                    doorStatus(3);
                }
                break;
            
            default:
                printf("Incorrect input. Press enter to continue.");
                hitEnter();
                break;
        }
    }
}

int checkInput(char inputText[])
{
    int length = strlen(inputText);
    if(length == 1 && (inputText[0] == ('x') || inputText[0] == 'X'))
    {
        return 1;
    }
    if(length > 3 && length < 7)
    {
        for(int i = 0; i < length; i++)
        {
            if(isdigit(inputText[i]) == 0)
            {
                return 3;
            }
        }
        return 2;
    }
    return 3;
}
