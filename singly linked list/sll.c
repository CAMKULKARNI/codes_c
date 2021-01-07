#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

void insert_at_pos(Node **head)
{
    printf("\nEnter the position");
    int pos;
    scanf("%d", &pos);

    if (pos == 0)
    {
        /* insert start */
        insert_start(head);
    }
    else if (pos == num_of_nodes(head))
    {
        /* insert end*/
        insert_end(head);
    }
    else if (pos > num_of_nodes(head))
    {
        printf("\nInvalid Position");
    }
    else
    {
        /* insert at pos */
        Node *ref = *head, *temp = (Node *)malloc(sizeof(Node));

        printf("\nEnter the data : ");
        scanf("%d", &(temp->data));

        for (int i = 0; i < pos - 1; i++)
        {
            ref = ref->next;
        }

        temp->next = ref->next;
        ref->next = temp;
    }
}

void insert_start(Node **head)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("\nEnter the data : ");
    scanf("%d", &(temp->data));
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

void insert_end(Node **head)
{
    Node *temp = (Node *)malloc(sizeof(Node)), *ref = *head;
    printf("\nEnter the data : ");
    scanf("%d", &(temp->data));
    temp->next = NULL;

    if (ref == NULL)
    {
        *head = temp;
    }
    else
    {
        while ((ref != NULL) && ((ref->next) != NULL))
        {
            ref = ref->next;
        }
        ref->next = temp;
    }
}

void display(Node *head)
{
    Node *ref = head;

    if (ref == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        while (ref != NULL)
        {
            printf("%d\t", ref->data);
            ref = ref->next;
        }
    }
}

int num_of_nodes(Node **head)
{
    Node *ref = *head;
    int count = 0;

    while ((ref != NULL) && ((ref->next) != NULL))
    {
        count++;
        ref = ref->next;
    }

    return count + 1;
}

void insert_before(Node **head)
{
    int nextData, currentData;
    printf("\nEnter the data before which you want to add : ");
    scanf("%d", &nextData);
    printf("\nEnter the data which you want to add : ");
    scanf("%d", &currentData);

    Node *ref = *head;
    while ((ref != NULL))
    {
        if ((ref->next != NULL) && (ref->next->data == nextData))
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = currentData;
            temp->next = ref->next;
            ref->next = temp;
            return;
        }
        else if (ref->data == nextData)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = currentData;
            temp->next = ref;
            *head = temp;
            return;
        }
        ref = ref->next;
    }

    if (ref == NULL)
    {
        printf("\nCould not find the data you entered. Please enter 1 to enter the node at the beginning, -1 to enter the node at the end or 0 to exit");
        int choice = 0;
        scanf("%d", &choice);

        if (choice == 1)
        {
            insert_start(head);
            return;
        }
        else if (choice == -1)
        {
            insert_end(head);
            return;
        }
        else if (choice == 0)
        {
            return;
        }
        else
        {
            printf("Invalid input !!");
            return;
        }
    }
}

void insert_after(Node **head)
{
    int prevData, currentData;
    printf("\nEnter the data after which you want to add : ");
    scanf("%d", &prevData);
    printf("\nEnter the data which you want to add : ");
    scanf("%d", &currentData);

    Node *ref = *head;
    while ((ref != NULL))
    {
        if (ref->data == prevData)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = currentData;
            temp->next = ref->next;
            ref->next = temp;
            return;
        }
        ref = ref->next;
    }

    if (ref == NULL)
    {
        printf("\nCould not find the data you entered. Please enter 1 to enter the node at the beginning, -1 to enter the node at the end or 0 to exit");
        int choice = 0;
        scanf("%d", &choice);

        if (choice == 1)
        {
            insert_start(head);
            return;
        }
        else if (choice == -1)
        {
            insert_end(head);
            return;
        }
        else if (choice == 0)
        {
            return;
        }
        else
        {
            printf("Invalid input !!");
            return;
        }
    }
}

void delete_at_pos(Node **head)
{
    printf("\nEnter the position");
    int pos;
    scanf("%d", &pos);

    if (pos == 0)
    {
        /* delete start */
        delete_start(head);
    }
    else if (pos == num_of_nodes(head))
    {
        /* delete end*/
        delete_end(head);
    }
    else if (pos > num_of_nodes(head))
    {
        printf("\nInvalid Position");
    }
    else
    {
        /* delete at pos */
        Node *ref = *head, *temp = (Node *)malloc(sizeof(Node));

        for (int i = 0; i < pos - 1; i++)
        {
            ref = ref->next;
        }

        temp = ref->next;
        ref->next = temp->next;
        free(temp);
    }
}

void delete_before(Node **head)
{
    return;
}

void delete_after(Node **head)
{
    int prevData, currentData;
    printf("\nEnter the data after which you want to delete : ");
    scanf("%d", &prevData);

    Node *ref = *head;
    while ((ref != NULL))
    {
        if (ref->data == prevData)
        {
            Node *temp = ref->next;
            ref->next = ref->next->next;
            free(temp);
            return;
        }
        ref = ref->next;
    }

    if (ref == NULL)
    {
        printf("\nCould not find the data you entered. Please enter 1 to delete the node at the beginning, -1 to delete the node at the end or 0 to exit");
        int choice = 0;
        scanf("%d", &choice);

        if (choice == 1)
        {
            delete_start(head);
            return;
        }
        else if (choice == -1)
        {
            delete_end(head);
            return;
        }
        else if (choice == 0)
        {
            return;
        }
        else
        {
            printf("Invalid input !!");
            return;
        }
    }
}

void delete_start(Node **head)
{
    Node *temp = *head;

    if (*head == NULL)
    {
        printf("\nThe list is empty");
    }
    else
    {
        *head = temp->next;
        free(temp);
    }
}

void delete_end(Node **head)
{
    Node *temp = *head;

    if (*head == NULL)
    {
        printf("\nThe list is empty");
    }
    else
    {
        while ((temp != NULL) && ((temp->next) != NULL) && ((temp->next->next) != NULL))
        {
            temp = temp->next;
        }
    }
    free(temp->next);
    temp->next = NULL;
}

void reverse(Node **head)
{
    Node *last = *head, *temp = (Node *)malloc(sizeof(Node));

    while ((last != NULL) && (last->next != NULL))
    {
        last = last->next;
    }

    while (last != *head)
    {
        temp = (*head)->next;
        (*head)->next = last->next;
        last->next = *head;
        *head = temp;
    }
}

void swap_node_data(Node **head)
{
    printf("\nEnter 1 to swap by number or 2 to swap by data");
    int choice = 0;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        /*Swap By Number*/
        break;
    case 2:
        /*Swap By Data*/
        break;
    default:
        printf("\nWrong Choice !! Enter a valid Number");
        break;
    }
}