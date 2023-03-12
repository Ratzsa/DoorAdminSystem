#ifndef _CARD_MANAGEMENT
#define _CARD_MANAGEMENT

typedef struct
{
    int cardNumber;
    int state;
} Card;

typedef struct
{
    Card *cards;
    int numberOfCards;
} CardStack;

void cardManager(CardStack *number);
void addCard(CardStack *number);
void inputCard(Card *new);
void setAccess();
bool findCard(int numberOfCards, int searchTarget);

#endif