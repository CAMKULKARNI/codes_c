#include <stdio.h>
#include <stdlib.h>
#include "week_11_5_server.h"
void bill(struct product *s)
{
    s->name = (char *)malloc(30 * sizeof(char));
    printf("\nEnter the name of the product : ");
    scanf("%s", s->name);
    printf("\nEnter the cost : ");
    scanf("%f", &s->cost);
    printf("\nEnter quantity : ");
    scanf("%d", &s->quantity);
}
void print_bill(struct product *s)
{
    printf("\nName of the product : %s", s->name);
    printf("\nCost : %f", s->cost);
    printf("\nQuantity : %d", s->quantity);
}