#include <stdio.h>
#include "week_15_1_server.h"
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("\n%d", a[i]);
}
int read(int a)
{
    scanf("%d", &a);
    return a;
}
void sort(int a[], int n)
{
    int swap, temp;
    for (int i = 0; i < n; i++)
    {
        swap = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                swap++;
            }
        }
        if (swap == 0)
            break;
    }
}