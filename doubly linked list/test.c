#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void display(Node *);

void insert_start(Node **);
void insert_end(Node **);
void delete_start(Node **);
void delete_end(Node **);
void insert_at_pos(Node **);
int num_of_nodes(Node **);
void delete_at_pos(Node **);
void reverse(Node **);

// void insert_before(Node **);
// void insert_after(Node **);

// void delete_before(Node **);
// void delete_after(Node **);

// void swap_node_data(Node **);

int main()
{
    Node *list = NULL;

    int choice = -1;

    while (choice != 0)
    {
        printf("\n0.  Exit");
        printf("\n1.  Insert at given position");
        printf("\n2.  Insert before a given Node");
        printf("\n3.  Insert after a given Node");
        printf("\n4.  Insert at start of the list");
        printf("\n5.  Insert at the end of the list");
        printf("\n6.  Delete At given position");
        printf("\n7.  Delete before a given Node");
        printf("\n8.  Delete after a given Node");
        printf("\n9.  Delete at the start of the list");
        printf("\n10. Delete at the end of the list");
        printf("\n11. Reverse the list");
        printf("\n12. Number of Nodes in the list");
        printf("\n13. Display");
        printf("\n14. Swap data of two Nodes");

        printf("\nEnter your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_at_pos(&list);
            break;
        // case 2:
        //     insert_before(&list);
        //     break;
        // case 3:
        //     insert_after(&list);
        //     break;
        case 4:
            insert_start(&list);
            break;
        case 5:
            insert_end(&list);
            break;
        case 6:
            delete_at_pos(&list);
            break;
        // case 7:
        //     delete_before(&list);
        //     break;
        // case 8:
        //     delete_after(&list);
        //     break;
        case 9:
            delete_start(&list);
            break;
        case 10:
            delete_end(&list);
            break;
        case 11:
            reverse(&list);
            break;
        // case 12:
        //     printf("\nThe number of nodes in the linked list is %d", num_of_nodes(&list));
        //     break;
        case 13:
            display(list);
            break;
            // case 14:
            //     swap_node_data(&list);
            //     break;
            // default:
            //     printf("Wrong Choice!! Enter another number");
            //     break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

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
        ref->next->prev = temp;
        temp->prev = ref;
        ref->next = temp;
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
        *head = temp;
    }
    else
    {
        temp->next = *head;
        temp->prev = NULL;
        *head = temp;
    }
}

void insert_end(Node **head)
{
    Node *temp = (Node *)malloc(sizeof(Node)), *ref = *head;
    printf("\nEnter the data : ");
    scanf("%d", &(temp->data));
    temp->next = NULL;
    temp->prev = NULL;

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
        temp->prev = ref;
        temp->next = NULL;
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

// void insert_before(Node **head)
// {
//     int nextData, currentData;
//     printf("\nEnter the data before which you want to add : ");
//     scanf("%d", &nextData);
//     printf("\nEnter the data which you want to add : ");
//     scanf("%d", &currentData);

//     Node *ref = *head;
//     while ((ref != NULL))
//     {
//         if ((ref->next != NULL) && (ref->next->data == nextData))
//         {
//             Node *temp = (Node *)malloc(sizeof(Node));
//             temp->data = currentData;
//             temp->next = ref->next;
//             ref->next = temp;
//             return;
//         }
//         else if (ref->data == nextData)
//         {
//             Node *temp = (Node *)malloc(sizeof(Node));
//             temp->data = currentData;
//             temp->next = ref;
//             *head = temp;
//             return;
//         }
//         ref = ref->next;
//     }

//     if (ref == NULL)
//     {
//         printf("\nCould not find the data you entered. Please enter 1 to enter the node at the beginning, -1 to enter the node at the end or 0 to exit");
//         int choice = 0;
//         scanf("%d", &choice);

//         if (choice == 1)
//         {
//             insert_start(head);
//             return;
//         }
//         else if (choice == -1)
//         {
//             insert_end(head);
//             return;
//         }
//         else if (choice == 0)
//         {
//             return;
//         }
//         else
//         {
//             printf("Invalid input !!");
//             return;
//         }
//     }
// }

// void insert_after(Node **head)
// {
//     int prevData, currentData;
//     printf("\nEnter the data after which you want to add : ");
//     scanf("%d", &prevData);
//     printf("\nEnter the data which you want to add : ");
//     scanf("%d", &currentData);

//     Node *ref = *head;
//     while ((ref != NULL))
//     {
//         if (ref->data == prevData)
//         {
//             Node *temp = (Node *)malloc(sizeof(Node));
//             temp->data = currentData;
//             temp->next = ref->next;
//             ref->next = temp;
//             return;
//         }
//         ref = ref->next;
//     }

//     if (ref == NULL)
//     {
//         printf("\nCould not find the data you entered. Please enter 1 to enter the node at the beginning, -1 to enter the node at the end or 0 to exit");
//         int choice = 0;
//         scanf("%d", &choice);

//         if (choice == 1)
//         {
//             insert_start(head);
//             return;
//         }
//         else if (choice == -1)
//         {
//             insert_end(head);
//             return;
//         }
//         else if (choice == 0)
//         {
//             return;
//         }
//         else
//         {
//             printf("Invalid input !!");
//             return;
//         }
//     }
// }

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
    else if (pos == num_of_nodes(head) - 1)
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
        temp->next->prev = temp->prev;
        free(temp);
    }
}

// void delete_before(Node **head)
// {
//     return;
// }

// void delete_after(Node **head)
// {
//     int prevData, currentData;
//     printf("\nEnter the data after which you want to delete : ");
//     scanf("%d", &prevData);

//     Node *ref = *head;
//     while ((ref != NULL))
//     {
//         if (ref->data == prevData)
//         {
//             Node *temp = ref->next;
//             ref->next = ref->next->next;
//             free(temp);
//             return;
//         }
//         ref = ref->next;
//     }

//     if (ref == NULL)
//     {
//         printf("\nCould not find the data you entered. Please enter 1 to delete the node at the beginning, -1 to delete the node at the end or 0 to exit");
//         int choice = 0;
//         scanf("%d", &choice);

//         if (choice == 1)
//         {
//             delete_start(head);
//             return;
//         }
//         else if (choice == -1)
//         {
//             delete_end(head);
//             return;
//         }
//         else if (choice == 0)
//         {
//             return;
//         }
//         else
//         {
//             printf("Invalid input !!");
//             return;
//         }
//     }
// }

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
        (*head)->prev = NULL;
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
    Node *last = *head, *temp = (Node *)malloc(sizeof(Node)), *ref = *head;

    while ((last != NULL) && (last->next != NULL))
    {
        last = last->next;
    }

    while (last != *head)
    {
        temp = (*head)->next;
        (*head)->next = last->next;
        (*head)->prev = last;
        last->next = (*head);
        (*head) = temp;
        (*head)->prev = NULL;
        last->next->next = NULL;
    }

    while (ref->prev->next == NULL)
    {
        ref->prev->next = ref;
        ref = ref->prev;
    }
}

// void swap_node_data(Node **head)
// {
//     printf("\nEnter 1 to swap by number or 2 to swap by data");
//     int choice = 0;
//     scanf("%d", &choice);

//     switch (choice)
//     {
//     case 1:
//         /*Swap By Number*/
//         break;
//     case 2:
//         /*Swap By Data*/
//         break;
//     default:
//         printf("\nWrong Choice !! Enter a valid Number");
//         break;
//     }
// }