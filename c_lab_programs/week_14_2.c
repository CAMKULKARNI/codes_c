#include <stdio.h>
#include <stdlib.h>
#include "week_14_2_server.h"
int main()
{
    struct linked_list *l;
    int n, num = 0;
    printf("\nEnter the number of elements to be present in the linked list : ");
    scanf("%d", &num);
    if (num > 0)
    {
        l = (struct linked_list *)malloc(num * sizeof(struct linked_list));
        (l + num - 1)->link = NULL;
        for (int i = 0; i < num - 1; i++)
        {
            (l + i)->link = (l + i + 1);
            printf("\nEnter the element %d of the linked list : ", i);
            scanf("%d", &(l + i)->data);
        }
        printf("\nEnter the element %d of the linked list : ", num - 1);
        scanf("%d", &(l + num - 1)->data);
    }
    else if (num == 0)
    {
        l->link = NULL;
        printf("\nThe linked list is empty");
    }
    else
        printf("\nInvalid input");
    do
    {
        printf("\n1.Display");
        printf("\n2.Delete at the front");
        printf("\n3.Delete at the end");
        printf("\n4.Search the element");
        printf("\n5.Product of nodes of a linked list which are divisible by a given number");
        printf("\n6.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &n);
        if (n == 1)
            display(l);
        else if (n == 2)
            delete_front(&l);
        else if (n == 3)
            delete_end(&l);
        else if (n == 4)
            search_element(l);
        else if (n == 5)
            product_nodes(l);
        else if (n != 6)
            printf("\nInvalid input");
    } while (n != 6);
    free(l);
    return 0;
}