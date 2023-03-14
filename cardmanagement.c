#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "mainmenu.h"
#include "doorstatus.h"
#include "systemfunctions.h"
#include "cardmanagement.h"
#include "cardtest.h"

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
                    setAccess(number);
                }
                break;

            case 3:
                managingCards = false;
                break;
            
            default:
                printf("Input error.");
                hitEnter();
                break;
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

    inputCard(&number->cards[number->numberOfCards - 1], number);
}

void inputCard(Card *new, CardStack *number)
{
    bool inputting = true;
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
            number->numberOfCards--;
        }
        else if(findCard(newCardNumber, number) != -1)
        {
            printf("Card already exists.\n");
            hitEnter();
            inputting = false;
            number->numberOfCards--;
        }
        else
        {
            new->cardNumber = newCardNumber;
            new->access = 2;
            new->dateAdded = time(0);
            inputting = false;
        }
    }
}

void setAccess(CardStack *number)
{
    int input;
    int menuInput;
    int cardExists;
    bool accessMenu = true;

    clearConsole();
    printf("Enter card number: ");
    scanf(" %d", &input);
    cardExists = findCard(input, number);

    if(cardExists < 0)
    {
        printf("Card not found.\n");
    }
    else
    {
        while(accessMenu)
        {
            printf("This card has ");
            if(number->cards[cardExists].access == 1)
            {
                printf("access.\n");
            }
            else
            {
                printf("no access.\n");
            }
            printf("Enter 1 for access, 2 for no access.\n");
            scanf(" %d", &menuInput);

            switch(menuInput)
            {
                case 1:
                    number->cards[cardExists].access = 1;
                    printf("Card has access.\n");
                    accessMenu = false;
                    break;

                case 2:
                    number->cards[cardExists].access = 2;
                    printf("Card has no access.\n");
                    accessMenu = false;
                    break;

                default:
                    printf("Incorrect input.\n");
                    accessMenu = false;
                    break;
            }
        }
    }
    hitEnter();
}

void listCards(const CardStack *number)
{
    char dateAdded[100];
    clearConsole();
    printf("All cards in system\n");
    for(int i = 0; i < number->numberOfCards; i++)
    {
        struct tm *convertedTime;
        convertedTime = localtime(&number->cards[i].dateAdded);
        strftime(dateAdded, 100, "%y-%m-%d", convertedTime);

        printf("%d\t", number->cards[i].cardNumber);
        if(number->cards[i].access == 1)
        {
            printf("ACCESS   \t");
        }
        else
        {
            printf("NO ACCESS\t");
        }
        printf("Date added: %s\n", dateAdded);
    }
    printf("Press enter to continue.");
    hitEnter();
}

int findCard(int cardNum, const CardStack *number)
{
    for(int i = 0; i < number->numberOfCards; i++)
    {
        if(number->cards[i].cardNumber == cardNum)
        {
            return i;
        }
    }
    return -1;
}