#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int top;
    char *operands;
} stack;

void palindrome(char *);
void push(stack *, char);
char pop(stack *);

int main()
{
    char *string = (char *)malloc(sizeof(char) * 256);
    printf("\nEnter the string : ");
    gets(string);
    palindrome(string);
    return 0;
}

void palindrome(char *string)
{
    int stringlen = strlen(string);
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->top = -1;
    newStack->operands = (char *)malloc(sizeof(char) * 256);

    if (stringlen % 2)
    {
        for (int i = 0; i < stringlen / 2; i++)
        {
            push(newStack, string[i]);
        }
        for (int i = (stringlen / 2) + 1; i < stringlen; i++)
        {
            if (string[i] == (newStack->operands)[newStack->top])
            {
                pop(newStack);
            }
        }
    }
    else
    {
        for (int i = 0; i < stringlen / 2; i++)
        {
            push(newStack, string[i]);
        }
        for (int i = (stringlen / 2); i < stringlen; i++)
        {
            if (string[i] == (newStack->operands)[newStack->top])
            {
                pop(newStack);
            }
        }
    }

    if (newStack->top == -1)
    {
        printf("\n\"%s\" is a palindrome", string);
    }
    else
    {
        printf("\n\"%s\" is not a palindrome", string);
    }
}

void push(stack *newStack, char operand)
{
    (newStack->top)++;
    (newStack->operands)[newStack->top] = operand;
}

char pop(stack *newStack)
{
    (newStack->top)--;
    return (newStack->operands)[(newStack->top) + 1];
}