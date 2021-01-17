#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main (void)
{
    int a;
    do
    {
        a = message(a);
        switch (a)
        {
            case 1: password_generation(); break;
            case 2: password_classification(); break;
            case 3: vigenere(); break;
            case 4: decryption(); break;
            case 5: exit(1); break;
            default: printf("Invalid Option. Please try again\n"); break;
        }
        printf("\n\n");
    } while (a != 5);

}