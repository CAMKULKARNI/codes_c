#include <stdio.h>
#include <stdlib.h>
#include "week_12_5_server.h"
int main()
{
    int *a, n;
    printf("\nEnter the number of elements to be entered : ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the element %d of the array : ", i);
        scanf("%d", (a + i));
    }
    populate(a, n);
    printf("\nThe squares of the entered elements are : ");
    for (int i = 0; i < n; i++)
        printf("\n%d", *(a + i));
    free(a);
    return 0;
}