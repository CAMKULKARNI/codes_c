#include <stdio.h>
#include <stdlib.h>
#include "week_14_1_server.h"
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
void insert_front(struct linked_list **l)
{
    struct linked_list *new_node = (struct linked_list *)malloc(sizeof(struct linked_list));
    printf("\nEnter the element to be inserted at the front : ");
    scanf("%d", &new_node->data);
    new_node->link = *l;
    *l = new_node;
}
void insert_end(struct linked_list **l)
{
    struct linked_list *new_node = (struct linked_list *)malloc(sizeof(struct linked_list)), *last = *l;
    printf("\nEnter the element to be entered at the end : ");
    scanf("%d", &new_node->data);
    new_node->link = NULL;
    if (*l == NULL)
    {
        *l = new_node;
        return;
    }
    while (last->link != NULL)
        last = last->link;
    last->link = new_node;
    return;
}
void sum_alternate(struct linked_list *l)
{
    int sum = 0, i = 0;
    struct linked_list *head = l;
    while (head)
    {
        if (!(i % 2))
            sum += head->data;
        head = head->link;
        i++;
    }
    printf("\n");
    printf("\nThe sum of alternate elements is %d", sum);
}
void sum(struct linked_list *l)
{
    int sum = 0;
    struct linked_list *head = l;
    while (head)
    {
        sum += head->data;
        head = head->link;
    }
    printf("\n");
    printf("\nThe sum of all elements is %d\n", sum);
}
void sum_even_odd(struct linked_list *l)
{
    int sum_odd = 0, sum_even = 0, i = 0;
    struct linked_list *head = l;
    while (head)
    {
        if (i % 2)
            sum_odd += head->data;
        else
            sum_even += head->data;
        head = head->link;
        i++;
    }
    printf("\n");
    ;
    printf("\nThe sum of elements at even nodes is %d", sum_even);
    printf("\nThe sum of elements at odd nodes is %d", sum_odd);
}