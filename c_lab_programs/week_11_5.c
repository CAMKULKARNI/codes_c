#include <stdio.h>
#include "week_11_5_server.h"
#include <stdlib.h>
int main()
{
    int n, total_bill = 0;
    printf("\nEnter the number of products : ");
    scanf("%d", &n);
    struct product *s = (struct product *)malloc(n * sizeof(struct product));
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter product %d details : ", i + 1);
        bill(s + i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n\nProduct details : ");
        print_bill(s + i);
    }
    for (int i = 0; i < n; i++)
        total_bill += ((s + i)->cost) * ((s + i)->quantity);
    printf("\nThe total bill is %d", total_bill);
    free(s);
    free(s->name);
    return 0;
}