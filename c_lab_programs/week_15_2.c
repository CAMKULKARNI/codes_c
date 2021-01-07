#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptr_1 = fopen("file_1.txt", "r");
    char ch;
    FILE *ptr_2 = fopen("file_2.txt", "r");
    FILE *ptr_3 = fopen("file_3.txt", "w");
    while ((ch = fgetc(ptr_1)) != EOF)
        fputc(ch, ptr_3);
    while ((ch = fgetc(ptr_2)) != EOF)
        fputc(ch, ptr_3);
    free(ptr_1);
    free(ptr_2);
    free(ptr_3);
    fclose(ptr_1);
    fclose(ptr_2);
    fclose(ptr_3);
    printf("\nThe two files have been merged succesfully\nOpen file3.txt to see the output");
    return 0;
}