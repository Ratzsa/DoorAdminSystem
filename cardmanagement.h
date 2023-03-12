#ifndef _CARD_MANAGEMENT
#define _CARD_MANAGEMENT

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
bool cardCreated(int numberOfCards, const CardStack *number);
void listCards(const CardStack *number);
int findCard(int cardNum, const CardStack *number);

#endif