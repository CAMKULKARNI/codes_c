#include <stdio.h>
#include <stdlib.h>
#include "week_14_2_server.h"
void display(struct linked_list *l)
{
    struct linked_list *head = l;
    while (head)
    {
        printf("\n%d", head->data);
        head = head->link;
    }
    printf("\n");
}
void delete_front(struct linked_list **l)
{
    if (!(*l))
        return;
    struct linked_list *ref = *l;
    *l = ref->link;
    free(ref);
    return;
}
void delete_end(struct linked_list **l)
{
    if (!(*l))
        return;
    struct linked_list *ref = *l;
    while ((ref->link)->link)
        ref = ref->link;
    free(ref->link);
    ref->link = NULL;
}
void search_element(struct linked_list *l)
{
    int n, i = 0;
    printf("\nEnter the element to be searched : ");
    scanf("%d", &n);
    struct linked_list *head = l;
    do
    {
        if (head->data == n)
        {
            printf("\nThe element %d is found at node %d", n, i);
            i = 0;
            break;
        }
        i++;
        head = head->link;
    } while (head);
    if (i)
        printf("\nThe element %d is not there in the linked list", n);
    printf("\n");
}
void product_nodes(struct linked_list *l)
{
    int product = 1, i = 0, n;
    printf("\nEnter the number : ");
    scanf("%d", &n);
    struct linked_list *head = l;
    do
    {
        if (!(i % n))
            product *= head->data;
        i++;
        head = head->link;
    } while (head);
    printf("\nProduct of nodes of a linked list which are divisible by %d is %d", n, product);
}