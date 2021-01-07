#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    struct Node *right, *left, *prev;
    char data;
} Node;

//Create Binary Expression tree from a string in postfix form  of length len
Node *createExpressionTree(char *a, int len);

//print the preorder traversal of the Binary Expression Tree
void preorder(Node *);

//print the postorder traversal of the Binary Expression Tree
void postorder(Node *);

//print the inorder traversal of the Binary Expression Tree
void inorder(Node *);

//Frees the space used by the Binary Expression Tree
void freeTree(Node *root);

int main()
{
    char postfix[100];
    int len;
    Node *root;
    int loop = 1, code;
    while (loop)
    {
        scanf("%d", &code);
        switch (code)
        {
        case 1:
            scanf("%s", postfix);
            len = strlen(postfix);
            root = createExpressionTree(postfix, len);
            break;

        case 2:
            inorder(root);
            printf("\n");
            break;

        case 3:
            preorder(root);
            printf("\n");
            break;

        case 4:
            postorder(root);
            printf("\n");
            break;

        default:
            loop = 0;
            break;
        }
    }
    return 0;
}

Node *createExpressionTree(char *a, int len)
{
    //TODO
    Node *stk[len];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        if (a[i] == 42 || a[i] == 43 || a[i] == 45 || a[i] == 47 || a[i] == 94 || a[i] == 36)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = a[i];
            temp->right = stk[top];
            top--;
            temp->left = stk[top];
            top--;
            temp->prev = NULL;
            top++;
            stk[top] = temp;
        }
        else
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = a[i];
            temp->left = NULL;
            temp->right = NULL;
            temp->prev = NULL;
            top++;
            stk[top] = temp;
        }
    }
    return stk[top];
}

void inorder(Node *root)
{
    //TODO
    // Note : Do not change the printf
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    //TODO
    // Note : Do not change the printf
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    //TODO
    // Note : Do not change the printf
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}
