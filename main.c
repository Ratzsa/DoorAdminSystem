#include <stdio.h>
#include <stdlib.h>
#include "mainmenu.h"

int main()
{
    FILE *temp = fopen("cards.crd", "rb");
    if(temp == NULL)
    {
        fclose(temp);
        temp = fopen("cards.crd", "wb");
    }
    fclose(temp);
    mainMenu();
    return 0;
}