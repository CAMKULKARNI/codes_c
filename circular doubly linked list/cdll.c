#include <stdio.h>
#include <stdlib.h>
#include "cdll.h"

void display(Node *head)
{
    if (head == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        Node *ref = head;
        do
        {
            printf("%d\t", ref->data);
            ref = ref->next;
        } while (ref != head);
    }
}

void insert_start(Node **head)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("\nEnter the data : ");
    scanf("%d", &(temp->data));
    temp->next = NULL;
    temp->prev = NULL;

    if (*head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        *head = temp;
    }
    else
    {
        temp->next = *head;
        (*head)->prev->next = temp;
        temp->prev = (*head)->prev;
        (*head)->prev = temp;
        *head = temp;
    }
}

void insert_end(Node **head)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("\nEnter the data : ");
    scanf("%d", &(temp->data));
    temp->next = NULL;
    temp->prev = NULL;

    if (*head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        *head = temp;
    }
    else
    {
        (*head)->prev->next = temp;
        temp->prev = (*head)->prev;
        temp->next = *head;
        (*head)->prev = temp;
    }
}

void delete_start(Node **head)
{
    Node *ref = *head;
    if (*head == NULL)
    {
        printf("\nEmpty list");
    }
    else if ((*head)->next == *head)
    {
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
        ref->prev->next = *head;
        (*head)->prev = ref->prev;
    }
    free(ref);
}

void delete_end(Node **head)
{
    Node *ref = *head;
    if (*head == NULL)
    {
        printf("\nEmpty list");
    }
    else if ((*head)->next == *head)
    {
        *head = NULL;
    }
    else
    {
        ref = (*head)->prev;
        ref->prev->next = ref->next;
        (*head)->prev = ref->prev;
    }
    free(ref);
}

int num_of_nodes(Node *head)
{
    int i = 0;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        Node *ref = head;
        do
        {
            i++;
            ref = ref->next;
        } while (ref != head);
    }
    return i;
}

void insert_at_pos(Node **head)
{
    int pos;
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    if (pos > num_of_nodes(*head) || pos < 0)
    {
        printf("\nInvalid position");
    }
    else if (pos == 0)
    {
        insert_start(head);
    }
    else if (pos == num_of_nodes(*head))
    {
        insert_end(head);
    }
    else
    {
        Node *ref = *head, *temp = (Node *)malloc(sizeof(Node));
        printf("\nEnter the data : ");
        scanf("%d", &(temp->data));
        temp->next = NULL;
        temp->prev = NULL;
        for (int i = 0; i < pos - 1; i++)
        {
            ref = ref->next;
        }
        temp->prev = ref;
        temp->next = ref->next;
        ref->next->prev = temp;
        ref->next = temp;
    }
}

void delete_at_pos(Node **head)
{
    // TODO
    int pos;
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    if (pos >= num_of_nodes(*head) || pos < 0)
    {
        printf("\nInvalid position");
    }
    else if (pos == 0)
    {
        delete_start(head);
    }
    else if (pos == num_of_nodes(*head) - 1)
    {
        delete_end(head);
    }
    else
    {
        Node *ref = *head;
        for (int i = 0; i < pos - 1; i++)
        {
            ref = ref->next;
        }
        ref->next = ref->next->next;
        ref->next->prev = ref;
        ref = ref->next;
        free(ref);
    }
}

void reverse(Node **head)
{
    // TODO
}