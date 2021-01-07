#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *name = (char *)malloc(sizeof(char) * 256);
    char *str = (char *)malloc(sizeof(char) * 256);
    int n;
    printf("\nEnter filename : ");
    scanf("%s", name);
    FILE *ptr_1 = fopen(name, "w");
    printf("\nEnter the number of lines : ");
    scanf("%d", &n);
    printf("\nThe lines are : ");
    for (int i = 0; i < n + 1; i++)
    {
        fgets(str, sizeof(str), stdin);
        fputs(str, ptr_1);
    }
    fclose(ptr_1);
    free(name);
    free(str);
}