#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int top;
    char *operands;
} stack;

// Function signatures
void brackets(char *);
void push(stack *, char);
char pop(stack *);

//the main function
int main()
{
    char string[256];
    printf("\nEnter the bracket string : ");
    gets(string);
    brackets(string);
    return 0;
}

// bracket matching function
void brackets(char *string)
{
    int i = 0;
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->top = -1;
    newStack->operands = (char *)malloc(sizeof(char) * 256);

    while (string[i] != '\0')
    {
        switch (string[i])
        {
        case '(':
        case '{':
        case '[':
            push(newStack, string[i]);
            break;
        case ')':
            if ((newStack->operands)[newStack->top] == '(')
            {
                pop(newStack);
            }
            else
            {
                push(newStack, string[i]);
            }
            break;
        case '}':
            if ((newStack->operands)[newStack->top] == '{')
            {
                pop(newStack);
            }
            else
            {
                push(newStack, string[i]);
            }
            break;
        case ']':
            if ((newStack->operands)[newStack->top] == '[')
            {
                pop(newStack);
            }
            else
            {
                push(newStack, string[i]);
            }
            break;
        }
        i++;
    }
    if (newStack->top == -1)
    {
        printf("\nBrackets are perfectly matched");
    }
    else
    {
        printf("\nThe brackets are mismatched");
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