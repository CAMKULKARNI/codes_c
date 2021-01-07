#include <stdio.h>
#include <stdlib.h>
#include "week_15_1_server.h"
int main()
{
    int n;
    printf("\nEnter number of elements to be sorted : ");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int));
    printf("\nEnter the desired values : ");
    for (int i = 0; i < n; i++)
        *(a + i) = read(*(a + i));
    printf("\nValues before sorting : ");
    display(a, n);
    sort(a, n);
    printf("\nValues after sorting : ");
    display(a, n);
    free(a);
}