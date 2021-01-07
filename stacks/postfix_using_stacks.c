#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct stack
{
    int top;
    int *operands;
} stack;

int postfixEval(char *);
void push(stack *, int);
int pop(stack *);

int main()
{
    char *expression = (char *)malloc(sizeof(char) * 256);
    gets(expression);
    printf("%d", postfixEval(expression));
    return 0;
}

int postfixEval(char *expression)
{
    int i = 0;
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->top = -1;
    newStack->operands = (int *)malloc(sizeof(int) * 2);

    while (expression[i])
    {
        if ((expression[i] <= 90 && expression[i] >= 65) || (expression[i] <= 122 && expression[i] >= 97))
        {
            int operand;
            printf("Enter the value of %c : ", expression[i]);
            scanf("%d", &operand);
            push(newStack, operand);
        }
        else
        {
            int operand_1 = pop(newStack), operand_2 = pop(newStack);
            switch (expression[i])
            {
            case 43:
                push(newStack, operand_1 + operand_2);
                break;
            case 45:
                push(newStack, -operand_1 + operand_2);
                break;
            case 47:
                push(newStack, operand_2 / operand_1);
                break;
            case 42:
                push(newStack, operand_1 * operand_2);
                break;
            case 37:
                push(newStack, operand_2 % operand_1);
                break;
            case 36:
                push(newStack, pow(operand_2, operand_2));
                break;
            default:
                printf("\nInvalid Symbol");
                break;
            }
        }
        i++;
    }

    return pop(newStack);
}

void push(stack *newStack, int operand)
{
    (newStack->top)++;
    (newStack->operands)[newStack->top] = operand;
}

int pop(stack *newStack)
{
    (newStack->top)--;
    return (newStack->operands)[(newStack->top) + 1];
}