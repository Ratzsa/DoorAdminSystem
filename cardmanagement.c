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
                inputCardToFile(number);
                break;

            case 2:
                setAccessInFile();
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
void inputCardToFile()
{
    int newCardNumber;
    Card searchCard;
    searchCard.cardNumber = -1;

    printf("Card number (4-6 digits): ");
    scanf(" %d", &newCardNumber);
    if(newCardNumber < 1000 || newCardNumber > 999999)
    {
        printf("Not a valid card number.\n");
        hitEnter();
    }
    else
    {
        searchCard = findCardInFile(newCardNumber);
        if(searchCard.cardNumber != -1)
        {
            printf("Card already exists.\n");
            hitEnter();
        }
        else
        {
            FILE *cardFile = fopen("cards.crd", "ab");
            if(cardFile == NULL)
            {
                printf("File error.\n");
                exit(1);
            }
            Card toFile;
            toFile.cardNumber = newCardNumber;
            toFile.access = 2;
            toFile.dateAdded = time(0);         
            fwrite(&toFile, sizeof(Card), 1, cardFile);
            fclose(cardFile);
        }
    }
}

/*
void writeToFile(void *scorelist, size_t size)
{
    FILE *scoreFile = fopen(fileName, "wb");
    fwrite(scorelist, size, 1, scoreFile);
    fclose(scoreFile);
}
*/

Card findCardInFile(int cardNum)
{
    FILE *cardFile = fopen("cards.crd", "rb");
    FILE *cardPtr;
    if(cardFile == NULL)
    {
        printf("File error.\n");
        exit(1);
    }
    Card returnCard;

    cardPtr = cardFile;
    while(!feof(cardPtr))
    {
        fread(&returnCard, sizeof(Card), 1, cardPtr);
        if(returnCard.cardNumber == cardNum)
        {
            fclose(cardFile);
            return returnCard;
        }
        cardFile = cardPtr;
    }
    fclose(cardFile);
    returnCard.cardNumber = -1;
    return returnCard;
}

void listCardsFromFile()
{
    Card listCard = {.cardNumber = -1};
    char dateAdded[100];

    FILE *cardFile = fopen("cards.crd", "rb");
    if(cardFile == NULL)
    {
        printf("File error or no cards entered. Press enter to continue.\n");
        hitEnter();
        return;
    }

    while(fread(&listCard, sizeof(Card), 1, cardFile) == 1)
    {
        // int p = fread(&listCard, sizeof(Card), 1, cardFile);
        
        struct tm *convertedTime;
        convertedTime = localtime(&listCard.dateAdded);
        strftime(dateAdded, 100, "%y-%m-%d", convertedTime);

        printf("%d\t", listCard.cardNumber);
        if(listCard.access == 1)
        {
            printf("ACCESS\t\t");
        }
        else
        {
            printf("NO ACCESS \t");
        }
        printf("Date added: %s\n", dateAdded);
        
    }
    fclose(cardFile);
    hitEnter();
}

void setAccessInFile()
{
    int setAccess = -1;
    int cardNum;
    FILE *cardFile = fopen("cards.crd", "rb+");
    FILE *cardPtr;
    if(cardFile == NULL)
    {
        printf("File error or no cards entered. Press enter to continue.\n");
        hitEnter();
        return;
    }
    Card accessCard;
    printf("Enter card number: ");
    scanf(" %d", &cardNum);
    clearInput();

    cardPtr = cardFile;
    while(!feof(cardPtr))
    {
        fread(&accessCard, sizeof(Card), 1, cardPtr);
        if(accessCard.cardNumber == cardNum)
        {
            printf("This card has ");
            if(accessCard.access == 1)
            {
                printf("access.\n");
            }
            else
            {
                printf("no access.\n");
            }
            printf("Enter 1 for access, 2 for no access.\n");
            scanf(" %d", &setAccess);

            switch(setAccess)
            {
                case 1:
                    accessCard.access = 1;
                    fwrite(&accessCard, sizeof(Card), 1, cardPtr);
                    printf("Card has access.\n");
                    fclose(cardFile);
                    hitEnter();
                    return;
                    break;

                case 2:
                    accessCard.access = 2;
                    fwrite(&accessCard, sizeof(Card), 1, cardPtr);
                    printf("Card has no access.\n");
                    fclose(cardFile);
                    hitEnter();
                    return;
                    break;

                default:
                    printf("Incorrect input.\n");
                    fclose(cardFile);
                    hitEnter();
                    return;
                    break;
            }
            fclose(cardFile);
            return;
        }
        cardFile = cardPtr;
    }
    printf("Card not found.");
    fclose(cardFile);
    return;
}

/*
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
    }*/


/*


void readFromFile(void *scorelist, size_t size)
{
    FILE *scoreFile = fopen(fileName, "rb");
    if(scoreFile != 0)
    {
        fread(scorelist, size, 1, scoreFile);
        fclose(scoreFile);
    }
}
*/

