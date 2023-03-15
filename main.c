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