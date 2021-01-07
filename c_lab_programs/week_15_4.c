#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main()
{
    FILE *fp1, *fp2;
    int lnum, lineCount = 0;
    char file[MAX], string[MAX];
    char newline[MAX], temp[] = "temp.txt";

    printf("Enter your input file name:");
    fgets(file, MAX, stdin);
    file[strlen(file) - 1] = '\0';

    fp1 = fopen(file, "r");

    if (!fp1)
    {
        printf("Unable to open the input file!!\n");
        exit(1);
    }

    fp2 = fopen(temp, "w");

    if (!fp2)
    {
        printf("Unable to open a temporary file to write!!\n");
        fclose(fp1);
        exit(1);
    }

    printf("Enter your new input line(to replace):");
    fgets(newline, MAX, stdin);

    printf("Enter the line no of the line you want to replace:");
    scanf("%d", &lnum);

    while (!feof(fp1))
    {
        strcpy(string, "\0");
        fgets(string, MAX, fp1);
        if (!feof(fp1))
        {
            lineCount++;
            if (lineCount != lnum)
            {
                fprintf(fp2, "%s", string);
            }
            else
            {
                fprintf(fp2, "%s", newline);
            }
        }
    }

    fclose(fp1);
    fclose(fp2);

    remove(file);

    rename(temp, file);
}