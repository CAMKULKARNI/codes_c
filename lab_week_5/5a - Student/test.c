#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
typedef struct Node Node;

struct List
{
    Node *head;
    int number_of_Nodes;
};

struct Node
{
    int data;
    Node *link;
};

void list_initialize(List *list);
void list_insert_front(List *list, int data);
void list_delete_front(List *list);
const int Node_get_data(Node *Node_ptr);
void list_destroy(List *list);

typedef struct Stack
{
    List *ptr_list;
} Stack;

void Stack_initialize(Stack *ptr_Stack);
void Stack_push(Stack *ptr_Stack, int data);
void Stack_pop(Stack *ptr_Stack);
int Stack_is_empty(Stack *ptr_Stack);
const int Stack_peek(Stack *ptr_Stack);
void Stack_destroy(Stack *ptr_Stack);
int match_parenthesis(const char *string);

int main()
{
    char *parenthesis_sequence = "(()";
    printf("%d\n", match_parenthesis(parenthesis_sequence));
    return 0;
}

void list_initialize(List *ptr_list)
{
    ptr_list->head = NULL;
    ptr_list->number_of_Nodes = -1;
}

void list_insert_front(List *ptr_list, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    if (ptr_list->head == NULL)
    {
        ptr_list->head = temp;
    }
    else
    {
        temp->link = ptr_list->head;
        ptr_list->head = temp;
    }
    (ptr_list->number_of_Nodes)++;
}

const int Node_get_data(Node *Node_ptr)
{
    return Node_ptr->data;
}

void list_delete_front(List *ptr_list)
{

    Node *temp = ptr_list->head;
    ptr_list->head = ptr_list->head->link;
    free(temp);
    (ptr_list->number_of_Nodes)--;
}

void list_destroy(List *ptr_list)
{
    Node *t = ptr_list->head, *u = NULL;
    while (t != NULL)
    {
        u = t;
        t = t->link;
        free(u);
    }
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack)
{
    ptr_Stack->ptr_list = (List *)malloc(sizeof(List));
    list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key)
{
    list_insert_front(ptr_Stack->ptr_list, key);
}

void Stack_pop(Stack *ptr_Stack)
{
    if (Stack_is_empty(ptr_Stack))
        list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack)
{
    if (ptr_Stack->ptr_list->number_of_Nodes == -1)
    {
        return 0;
    }
    return 1;
}

const int Stack_peek(Stack *ptr_Stack)
{
    if (Stack_is_empty(ptr_Stack))
        return (ptr_Stack->ptr_list->head->data);
}

void Stack_destroy(Stack *ptr_Stack)
{
    list_destroy(ptr_Stack->ptr_list);
    free(ptr_Stack);
}

int match_parenthesis(const char *string)
{
    int i = 0;
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    Stack_initialize(newStack);

    while (string[i] != '\0')
    {
        switch (string[i])
        {
        case '(':
        case '{':
        case '[':
            Stack_push(newStack, string[i]);
            break;
        case ')':
            if (Stack_peek(newStack) == '(')
            {
                Stack_pop(newStack);
            }
            else
            {
                Stack_push(newStack, string[i]);
            }
            break;
        case '}':
            if (Stack_peek(newStack) == '{')
            {
                Stack_pop(newStack);
            }
            else
            {
                Stack_push(newStack, string[i]);
            }
            break;
        case ']':
            if (Stack_peek(newStack) == '[')
            {
                Stack_pop(newStack);
            }
            else
            {
                Stack_push(newStack, string[i]);
            }
            break;
        }
        i++;
    }

    if (newStack->ptr_list->number_of_Nodes == -1)
    {
        Stack_destroy(newStack);
        return 1;
    }
    else
    {
        Stack_destroy(newStack);
        return 0;
    }
}