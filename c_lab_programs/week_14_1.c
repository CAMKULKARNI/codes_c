#include <stdio.h>
#include <stdlib.h>
#include "week_14_1_server.h"
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
        printf("\n2.Insert at the front");
        printf("\n3.Insert at the end");
        printf("\n4.Sum of alternate node elements");
        printf("\n5.Sum of all the elements in the list");
        printf("\n6.Sum of even and odd node elements in the list");
        printf("\n7.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &n);
        if (n == 1)
            display(l);
        else if (n == 2)
            insert_front(&l);
        else if (n == 3)
            insert_end(&l);
        else if (n == 4)
            sum_alternate(l);
        else if (n == 5)
            sum(l);
        else if (n == 6)
            sum_even_odd(l);
        else if (n != 7)
            printf("\nInvalid input");
    } while (n != 7);
    return 0;
}