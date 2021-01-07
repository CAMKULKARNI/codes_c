#include <stdio.h>
#include "week_12_1_server.h"
void array(int *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the element %d : ", i);
        scanf("%d", s + i);
    }
    printf("\nArray before permutation : ");
    for (int i = 0; i < n; i++)
        printf("\n%d", *(s + i));
    printf("\nThe array after a cyclic permutation is : ");
    *(s + n - 1) = *s;
    for (int i = 0; i < n - 1; i++)
        *s = *(s + i + 1);
    for (int i = 0; i < n; i++)
        printf("\n%d", *(s + i));
}