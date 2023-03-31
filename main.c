/*
Använder unistd.h som enda icke helt 100% standardbibliotek (tror jag).
Hade en funktion för delay som använder clock() men tydligen gör den funktionen att processorn arbetar hela tiden,
och det är nog inte helt bra för lite äldre datorer. Gick därför tillbaka till sleep() från unistd.h som
jag använder två gånger i doorstatus.c för att lampan ska bli grön eller röd.

void delay()
{
    clock_t delay = clock() + 3000;
    while(delay > clock())
    {

    }
}

*/

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
    if(temp == NULL)
    {
        printf("File error, exiting program.\n");
    }
    fclose(temp);
    mainMenu();
    return 0;
}