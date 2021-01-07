#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *insert(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node)), *ref = head;
    temp->data = data;
    temp->next = NULL;

    if (ref == NULL)
    {
        return temp;
    }

    while (ref->next != NULL)
    {
        ref = ref->next;
    }
    ref->next = temp;

    return head;
}

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    node *head, *ref = head;

    for (int i = 0; i < n; i++)
    {
        head = insert(head, i);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", ref->data);
        ref = ref->next;
    }
}