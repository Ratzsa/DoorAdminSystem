#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "systemfunctions.h"
#include "cardmanagement.h"

void cardManager()
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
                inputCardToFile();
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

Card findCardInFile(int cardNum)
{
    FILE *cardFile = fopen("cards.crd", "rb");
    if(cardFile == NULL)
    {
        printf("File error.\n");
        exit(1);
    }
    Card returnCard;

    while(!feof(cardFile))
    {
        fread(&returnCard, sizeof(Card), 1, cardFile);
        if(returnCard.cardNumber == cardNum)
        {
            fclose(cardFile);
            return returnCard;
        }
    }
    fclose(cardFile);
    returnCard.cardNumber = -1;
    return returnCard;
}

void listCardsFromFile()
{
    clearConsole();
    Card listCard = {.cardNumber = -1};
    char dateAdded[100];

    FILE *cardFile = fopen("cards.crd", "rb");
    if(cardFile == NULL)
    {
        printf("File error or no cards entered. Press enter to continue.\n");
        hitEnter();
        return;
    }

    printf("All cards in system\n");

    while(fread(&listCard, sizeof(Card), 1, cardFile) == 1)
    {
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
    printf("Press enter to continue.\n");
    hitEnter();
}

void setAccessInFile()
{
    int setAccess = -1;
    int cardNum;
    int found = 0;
    int structCounter = 0;
    int hasAccess = 1;
    int noAccess = 2;

    FILE *cardFile = fopen("cards.crd", "rb+");
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

    while(!feof(cardFile))
    {
        fread(&accessCard, sizeof(Card), 1, cardFile);
        if(accessCard.cardNumber == cardNum)
        {
            found++;
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
                    accessCard.access = hasAccess;
                    fseek(cardFile, sizeof(Card) * structCounter, SEEK_SET);
                    fwrite(&accessCard, sizeof(Card), 1, cardFile);
                    printf("Card has access.\n");
                    fclose(cardFile);
                    hitEnter();
                    break;

                case 2:
                    accessCard.access = noAccess;
                    fseek(cardFile, sizeof(Card) * structCounter, SEEK_SET);
                    fwrite(&accessCard, sizeof(Card), 1, cardFile);
                    printf("Card has no access.\n");
                    fclose(cardFile);
                    hitEnter();
                    break;

                default:
                    printf("Incorrect input.\n");
                    fclose(cardFile);
                    hitEnter();
                    break;
            }
            return;
        }
        structCounter++;
    }

    if(found == 0)
    {
        printf("Card not found.");
        clearInput();
    }
    
    fclose(cardFile);
}