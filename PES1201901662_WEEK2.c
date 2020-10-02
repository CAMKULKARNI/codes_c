#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data)
{
    Node *ref = (Node *)malloc(sizeof(Node)), *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    if (list->head == NULL)
    {
        list->head = temp;
    }
    else
    {
        ref = list->head;
        while (ref->link != NULL)
        {
            ref = ref->link;
        }
        ref->link = temp;
        list->number_of_nodes++;
    }
}

void list_delete_front(List *list)
{
    Node *temp = list->head;
    list->head = list->head->link;
    free(temp);
    list->number_of_nodes--;
}

void list_insert_at(List *list, int data, int position)
{
    Node *ref = (Node *)malloc(sizeof(Node)), *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;
    ref = list->head;

    if (position == 0)
    {
        temp->link = list->head;
        list->head = temp;
    }
    else if (position == list->number_of_nodes)
    {
        insert_at_end(list, data);
    }
    else
    {
        for (int i = 1; i < position - 1; i++)
        {
            ref = ref->link;
        }
        temp->link = ref->link;
        ref->link = temp;
    }
    list->number_of_nodes++;
}

void list_reverse(List *list)
{
    Node *temp = NULL, *ref = (Node *)malloc(sizeof(Node)), *copy = NULL;
    while (ref != NULL)
    {
        copy = ref->link;
        ref->link = temp;
        temp = ref;
        ref = copy;
    }
    list->head = temp;
}
