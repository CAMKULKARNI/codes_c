#include <stdio.h>
#include "week_12_1_server.h"
#include <stdlib.h>
int main()
{
    int n, *p;
    printf("\nEnter the number of elements : ");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(n));
    array(p, n);
    return 0;
}