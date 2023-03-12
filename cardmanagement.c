#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "mainmenu.h"
#include "opendoor.h"
#include "systemfunctions.h"
#include "cardmanagement.h"

void cardManager(CardStack *number)
{
    bool managingCards = true;
    int cardMenuInput;

    while(managingCards)
    {
        clearConsole();
        printf("1. Add card\n");
        printf("2. Card access\n");
        printf("3. Return\n");
        
        scanf(" %d", &cardMenuInput);

        switch(cardMenuInput)
        {
            case 1:
                addCard(number);
                break;

            case 2:
                if(number->numberOfCards == 0)
                {
                    printf("No cards have been entered.\n");
                    hitEnter();
                }
                else
                {
                    setAccess();
                }
                break;

            case 3:
                managingCards = false;
                break;
            
            default:
                printf("Input error.");
                hitEnter();
                
        }
    }
}


void addCard(CardStack *number)
{
    number->numberOfCards++;

    if(number->numberOfCards == 1)
    {
        number->cards = (Card *)malloc(1 * sizeof(Card));
    }
    else
    {
        number->cards = (Card *)realloc(number->cards, number->numberOfCards * sizeof(Card));
    }

    inputCard(&number->cards[number->numberOfCards - 1]);
}

void inputCard(Card *new)
{
    bool inputting = true;
    // bool cardExists = false;
    int newCardNumber;

    while(inputting)
    {
        printf("Card number (4-6 digits): ");
        scanf(" %d", &newCardNumber);
        if(newCardNumber < 1000 || newCardNumber > 999999)
        {
            inputting = false;
            printf("Not a valid card number.\n");
            hitEnter();
        }
        else
        {
            new->cardNumber = newCardNumber;
            new->state = 2;
            inputting = false;
        }
    }
}

void setAccess()
{
    printf("Set access selected.\nThings work so far!\n");
    hitEnter();
}

bool findCard(int numberOfCards, int searchTarget)
{
    

    return true;
}