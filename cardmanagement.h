#ifndef _CARD_MANAGEMENT
#define _CARD_MANAGEMENT

#include <time.h>

typedef struct
{
    int cardNumber;
    int access;
    time_t dateAdded;
} Card;

typedef struct
{
    Card *cards;
    int numberOfCards;
} CardStack;

void cardManager(CardStack *number);
void addCard(CardStack *number);
void inputCard(Card *new, CardStack *number);
void setAccess(CardStack *number);
void listCards(const CardStack *number);
int findCard(int cardNum, const CardStack *number);
Card findCardInFile(int cardNum);
void inputCardToFile();
void listCardsFromFile();
void setAccessInFile();

#endif