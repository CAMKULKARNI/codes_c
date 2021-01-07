#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree
{
    Node *root;
} Tree;

void tree_initialize(Tree *tree);
void tree_insert(Tree *tree, int data);
void inorder(Tree *tree);
void preorder(Tree *tree);
void postorder(Tree *tree);
void tree_delete(Tree *tree, int data);
void tree_destroy(Tree *tree);

void tree_initialize(Tree *tree)
{
    tree = (Tree *)malloc(sizeof(Tree));
    //tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    // TODO : Insert element to create a BST
    // If tree is empty
    if (tree->root == NULL)
    {
        tree->root->data = data;
    }
    else
    {
        // Temp variable for traversal
        Node *temp = tree->root;
        // Parent node
        Node *parent;
        while (temp != NULL)
        {
            parent = temp;
            // If data is greater
            if (data > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        // Creating new node
        Node *new = malloc(sizeof(Node));
        new->data = data;
        new->right = NULL;
        new->left = NULL;
        // Comparing parent data
        if (data > parent->data)
        {
            parent->right = new;
        }
        else
        {
            parent->left = new;
        }
    }
}
void tree_delete(Tree *tree, int element)
{
    // If tree is not empty
    if (tree->root != NULL)
    {
        // If node to be deleted is root node
        if (tree->root->data == element)
        {
            // If tree has no children
            if (tree->root->right == NULL && tree->root->left == NULL)
            {
                tree->root = NULL;
            }
            // If tree has one child
            else if (tree->root->right == NULL || tree->root->left == NULL)
            {
                if (tree->root->right == NULL)
                {
                    Node *del = tree->root;
                    tree->root = tree->root->left;
                    free(del);
                }
                else
                {
                    Node *del = tree->root;
                    tree->root = tree->root->right;
                    free(del);
                }
            }
            // If it has two children
            else if (tree->root->right != NULL && tree->root->left != NULL)
            {
                // Must find inorder successor
                Node *parent = tree->root;
                Node *temp = tree->root->right;
                // If temp does not have a left child, temp is the inorder successor
                if (temp->left == NULL)
                {
                    tree->root->data = temp->data;
                    parent->right = NULL; // As temp is the right child of parent
                    free(temp);
                }
                // If temp has a right child, then left most child of resulting subtree is the inorder successor
                else if (temp->left != NULL)
                {
                    while (temp->right != NULL && temp->left != NULL)
                    {
                        parent = temp;
                        temp = temp->left;
                    }
                    // Temp is node to be deleted and parent is parent node of temp
                    tree->root->data = temp->data;
                    // Now temp has to be deleted, it is the left child of parent
                    parent->left = NULL;
                    free(temp);
                }
            }
        }
        // If node to be deleted is not root
        else
        {
            // First must go to node
            Node *del = tree->root;
            Node *parent;
            while (del != NULL && del->data != element)
            {
                parent = del;
                if (element > del->data)
                {
                    del = del->right;
                }
                else if (element < del->data)
                {
                    del = del->left;
                }
            }
            // If del is not NULL, only then the element is present
            if (del != NULL)
            {
                // If node to be deleted has no children
                if (del->right == NULL && del->left == NULL)
                {
                    if (parent->right->data == del->data)
                    {
                        parent->right = NULL;
                    }
                    else
                    {
                        parent->left = NULL;
                    }
                    free(del);
                }
                // If the node has one child
                else if (del->right == NULL || del->left == NULL)
                {
                    // If it has a right child
                    if (del->right != NULL && del->left == NULL)
                    {
                        // If del is the right child of parent
                        if (parent->right->data == del->data)
                        {
                            parent->right = del->right;
                        }
                        // If del is the left child of parent
                        else if (parent->left->data == del->data)
                        {
                            parent->left = del->right;
                        }
                    }
                    // If it has a left child
                    else if (del->right == NULL && del->left != NULL)
                    {
                        // If del is the right child of parent
                        if (parent->right->data == del->data)
                        {
                            parent->right = del->left;
                        }
                        // If del is the left child of parent
                        else if (parent->left->data == del->data)
                        {
                            parent->left = del->left;
                        }
                    }
                    free(del);
                }
                // If the node has two children
                else if (del->right != NULL && del->left != NULL)
                {
                    // Find the inorder successor
                    Node *parent = del;
                    Node *temp = del->right;
                    // If temp does not have a left child, temp is the inorder successor
                    if (temp->left == NULL)
                    {
                        parent->data = temp->data;
                        parent->right = NULL; // As temp is the right child of parent
                        free(temp);
                    }
                    // If temp has a right child, then left most child of resulting subtree is the inorder successor
                    else if (temp->left != NULL)
                    {
                        while (temp->right != NULL && temp->left != NULL)
                        {
                            parent = temp;
                            temp = temp->left;
                        }
                        // Temp is node to be deleted and parent is parent node of temp
                        del->data = temp->data;
                        // Now temp has to be deleted, it is the left child of parent
                        parent->left = NULL;
                        free(temp);
                    }
                }
            }
        }
    }
}

void tree_inorder(Node *r)
{
    if (r != NULL)
    {
        tree_inorder(r->left);
        printf("%d\n", r->data);
        tree_inorder(r->right);
    }
}

void tree_preorder(Node *r)
{
    if (r != NULL)
    {
        printf("%d\n", r->data);
        tree_preorder(r->left);
        tree_preorder(r->right);
    }
}

void tree_postorder(Node *r)
{
    if (r != NULL)
    {
        tree_postorder(r->left);
        tree_postorder(r->right);
        printf("%d\n", r->data);
    }
}

void postorder(Tree *t)
{
    // If tree is not empty
    if (t->root != NULL)
    {
        tree_postorder(t->root);
    }
}

void preorder(Tree *t)
{
    // If tree is not empty
    if (t->root != NULL)
    {
        tree_preorder(t->root);
    }
}

void inorder(Tree *t)
{
    // If tree is not empty
    if (t->root != NULL)
    {
        tree_inorder(t->root);
    }
}

void destroy(Node *r)
{
    if (r != NULL)
    {
        destroy(r->left);
        destroy(r->right);
        free(r);
    }
}

void tree_destroy(Tree *t)
{
    // If tree not empty
    if (t->root != NULL)
    {
        destroy(t->root);
    }
}

int main()
{
    int choice, loop = 1;
    Tree my_tree;
    tree_initialize(&my_tree);
    while (loop)
    {
        scanf("%d", &choice);
        switch (choice)
        {
            int number_of_elements, element, index;
            int data;
        case 1:
            /* Insert elements */
            scanf("%d", &element);
            tree_insert(&my_tree, element);
            break;
        case 2:
            /* Print elements in the preorder fashion */
            preorder(&my_tree);
            break;
        case 3:
            /* Print elements in the inorder fashion */
            inorder(&my_tree);
            break;
        case 4:
            /* Print elements in the postorder fashion */
            postorder(&my_tree);
            break;
        case 5:
            /* Delete elements */
            scanf("%d", &element);
            tree_delete(&my_tree, element);
            break;
        default:
            tree_destroy(&my_tree);
            loop = 0;
            break;
        }
    }
    return 0;
}
