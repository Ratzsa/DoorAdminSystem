#ifndef _CARD_MANAGEMENT
#define _CARD_MANAGEMENT

#include <time.h>

typedef struct
{
    int cardNumber;
    int access;
    time_t dateAdded;
} Card;

void cardManager();
Card findCardInFile(int cardNum);
void inputCardToFile();
void listCardsFromFile();
void setAccessInFile();

#endif