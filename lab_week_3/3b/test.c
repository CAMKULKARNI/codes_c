#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List
{
    Node *head;
    Node *tail;
    int number_of_nodes;
} List;

// initializes a linked list
List *initialize_list();

// Inserts data at the beginning of the List
void insert_front(List *dll, int data);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List *dll);

// Return index of key in the list(0-based). Return -1 if not found
void reverse_list(List *dll);

int count_nodes(List *dll);

int main()
{
    List *dll = initialize_list();
    int ele, choice, pos, x, input[] = {1, 1, 1, 2, 1, 3, 7, 6, 7}, i = 0, n = 6;
    do
    {
        choice = input[i];
        i++;
        switch (choice)
        {
        case 1:
            ele = input[i];
            i++;
            insert_front(dll, ele);
            break;
        case 6:
            reverse_list(dll);
            break;
        case 7:
            display(dll);
            break;
        }
    } while (i < 9);

    return 0;
}

List *initialize_list()
{
    List *dll = (List *)malloc(sizeof(List));
    dll->head = NULL;
    dll->number_of_nodes = 0;

    return dll;
}

void display(List *dll)
{
    if (dll->number_of_nodes == 0)
        printf("EMPTY");
    else
    {
        Node *temp = dll->head;

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }

    printf("\n");
}

int count_nodes(List *dll)
{
    Node *ref = dll->head;
    int count = 0;

    if (ref == NULL)
    {
        return count;
    }

    while ((ref->next) != NULL)
    {
        count++;
        ref = ref->next;
    }

    return count + 1;
}

void insert_front(List *dll, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (dll->head == NULL)
    {
        dll->head = temp;
        dll->tail = temp;
    }
    else
    {
        temp->next = dll->head;
        dll->head->prev = temp;
        dll->head = temp;
    }
    dll->number_of_nodes++;
}

void reverse_list(List *dll)
{
    // Node *temp = NULL, *current = dll->head;
    // dll->tail = dll->head;

    // while (current != NULL)
    // {
    //     temp = current->prev;
    //     current->prev = current->next;
    //     current->next = temp;
    //     current = current->prev;
    // }

    // if (temp != NULL)
    //     dll->head = temp->prev;

    while (dll->head->next != NULL)
    {
        Node *temp = dll->head, *refer = temp->prev;
        temp->prev = dll->head->next;
        dll->head = dll->head->next;
        temp->next = refer;
    }
    dll->head->next = dll->head->prev;
    dll->head->prev = NULL;
}
