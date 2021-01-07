#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    tree = malloc(sizeof(tree));
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    // Create new node
    Node* new = malloc(sizeof(Node));
	new->data = data;
	// Has thread by default
	new->leftThread = 1;
	new->rightThread = 1;
	// flag variable, 0 is temp is null, 1 if has thread
	int flag = 0;
    // If tree is empty
    if (tree->root == NULL)
    {
        tree->root = new;
        new->right = NULL;
        new->left = NULL;
        // 0 if no threads
        new->leftThread = 0;
        new->rightThread = 0;
    }
	else
	{
		// Temp node for traversal
		Node* temp = tree->root;
		// Parent node
		Node* parent = NULL;
		while (temp != NULL)
		{
			parent = temp;
			// If node is greater, go right
			if (new->data > temp->data)
			{
				// If it is threaded
				if (temp->rightThread == 1)
				{
					flag = 1;
					break;
				}
				else 
				{
					temp = temp->right;
				}
			}
			else if (new->data < temp->data)
			{
				// If it is threaded
				if (temp->leftThread == 1)
				{
					flag = 1;
					break;
				}
				else 
				{
					temp = temp->left;
				}
			}
			// If it is threaded
			if (flag == 1)
			{
				// If it is threaded, parent == temp
				// If it is larger and has right thread
				if (new->data > parent->data && parent->rightThread == 1)
				{
					// Right thread of new is right thread of parent
					new->right = parent->right;
					// Right of parent is now new
					parent->right = new;
					// As parent is not rightThreaded, need to set to 0
					parent->rightThread = 0;
					// Left thread of new will be parent
					new->left = parent;
				}
				// If it is smaller and has left thread
				else if (new->data < parent->data && parent->leftThread == 1)
				{
					// Left thread of new is left thread of parent
					new->left = parent->left;
					// Left of parent is now new
					parent->left = new;
					// As parent is not leftThreaded, need to set to 0
					parent->leftThread = 0;
					// Right thread of new will be parent
					new->right = parent;
				}
			}
			// If it is not threaded, then temp == NULL
			else if (flag == 0 && temp == NULL)
			{
				// If it is smaller than parent
				if (new->data < parent->data)
				{
					// As not threaded, no need to set threads
					parent->left = new;
					// Right thread of new will be parent
					new->right = parent;
					// No left thread
					new->leftThread = 0;
					new->left = NULL;
				}
				// If it is larger than parent
				else if (new->data > parent->data)
				{
					// As not threaded, no need to set threads
					parent->right = new;
					// Left thread of new will be parent
					new->left = parent;
					// No right thread
					new->rightThread = 0;
					new->right = NULL;
				}
			}
		}
	}
}

Node *inorder_predecessor(Node *ptr)
{
	// If node is empty
	if (ptr == NULL)
	{
		return NULL;
	}
	// If the node is left threaded
	else if (ptr->leftThread == 1)
	{
		return ptr->left;
	}
	// If the node is not threaded, has left child
	else if (ptr->leftThread == 0)
	{
		Node* temp = ptr->left;
		// If temp is not null
		if (temp != NULL)
		{
			// Traverse till it is not null
			while (temp->right != NULL)
			{
				temp = temp->right;
			}
		}
		return temp;
	}
}

Node *inorder_successor(Node *ptr)
{
	// If node is empty
	if (ptr == NULL)
	{
		return NULL;
	}
	// If the node is right threaded
	else if (ptr->rightThread == 1)
	{
		return ptr->right;
	}
	else if (ptr->rightThread == 0)
	{
		Node* temp = ptr->right;
		// If temp is not null
		if (temp != NULL)
		{
			// Traverse till it is not null
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
		}
		return temp;
	}
   
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
	// Go to left most node
	Node* temp = tree->root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	// Get inorder successor and continue
	while (inorder_successor(temp) != NULL)
	{
		printfun(temp->data);
		temp = inorder_successor(temp);
	}
	printfun(temp->data);
	nextline();
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
	// Go to right most node
	Node* temp = tree->root;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	// Get inorder predecessor and continue
	while (inorder_predecessor(temp) != NULL)
	{
		printfun(temp->data);
		temp = inorder_predecessor(temp);
	}
	printfun(temp->data);
	nextline();
}

void destroy(Node *r)
{
    //TODO
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}
