#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *ptr1 = fopen("file_1.txt", "r");
    FILE *ptr2 = fopen("file_2.txt", "r");
    printf("Comparing file1.txt and file2.txt\n");
    char ch1, ch2;
    ch1 = fgetc(ptr1);
    ch2 = fgetc(ptr2);
    printf("The result is: \n");
    int y = 0;
    while (1)
    {
        if (ch1 == EOF || ch2 == EOF)
        {
            if (ch1 == ch2)
            {
                y = 0;
                break;
            }
            else
            {
                y = 1;
                break;
            }
        }
        if (ch1 != ch2)
        {
            y = 1;
            break;
        }
        ch1 = fgetc(ptr1);
        ch2 = fgetc(ptr2);
    }

    if (y == 0)
    {
        printf("The files are the same\n");
    }
    else if (y == 1)
    {
        printf("The files are different\n");
    }
    fclose(ptr1);
    fclose(ptr2);
}