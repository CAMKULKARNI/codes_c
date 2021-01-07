#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trienode
{
    struct trienode *child[26];
    int endofword;
};

struct trienode *getnode();
void insert(struct trienode *, char *);
void display(struct trienode *);

int main()
{
    struct trienode *root;
    char *key = "abc\0";
    root = getnode();
    insert(root, key);
    display(root);
    return 0;
}

struct trienode *getnode()
{
    //TODO
    struct trienode *temp = (struct trienode *)malloc(sizeof(struct trienode));
    for (int i = 0; i < 26; i++)
    {
        temp->child[i] = NULL;
    }
    temp->endofword = 0;

    return temp;
}

void insert(struct trienode *root, char *key)
{
    struct trienode *ref = root;

    for (int i = 0; key[i] != '\0'; i++)
    {
        int index = key[i] - 'a';
        if (ref->child[index] == NULL)
        {
            ref->child[index] = getnode();
        }
        ref = ref->child[index];
    }
    ref->endofword = 1;
}

int length = 0;
char word[256];

void display(struct trienode *curr)
{
    //TODO:
    //Note : DO NOT USE printf() statement, use printfun() and   newline function for printing output
    for (int i = 0; i < 26; i++)
    {
        if (curr->child[i] != NULL)
        {
            word[length++] = i + 97;
            if (curr->endofword == 1)
            {
                printf("\n");
                for (int j = 0; j < length; j++)
                {
                    printf("%c", word[j]);
                }
            }
            display(curr->child[i]);
        }
    }
    length--;
    return;
}