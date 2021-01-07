#include <stdio.h>
#include "bst.h"

void tree_initialize(Tree *tree)
{
	//TODO
	tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
	// TODO : Insert element to create a BST
	Node *r = tree->root;
	Node *parent;
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		return;
	}
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	if (r == NULL)
	{
		tree->root = temp;
		return;
	}
	while (r != NULL)
	{
		parent = r;
		if (temp->data < r->data)
		{
			r = r->left;
		}
		else
		{
			r = r->right;
		}
	}
	if (temp->data < parent->data)
	{
		parent->left = temp;
	}
	else
	{
		parent->right = temp;
	}
}
void tree_delete(Tree *tree, int element)
{
	// TODO : Delete elements from BST
	Node *r = tree->root;
	Node *parent = NULL;
	Node *temp;
	Node *insucc;
	Node *insucc_parent = NULL;
	while (r != NULL && r->data != element)
	{
		parent = r;
		if (element < r->data)
			r = r->left;
		else
			r = r->right;
	}
	if (r == NULL)
		return;
	if (r->left == NULL)
	{
		temp = r->right;
		free(r);
	}
	else if (r->right == NULL)
	{
		temp = r->left;
		free(r);
	}
	else
	{
		insucc = r->right;
		if (insucc != NULL)
		{
			while (insucc->left != NULL)
			{
				insucc_parent = insucc;
				insucc = insucc->left;
			}
			r->data = insucc->data;
			if (insucc_parent == NULL)
				r->right = insucc->right;
			else
			{
				insucc_parent->left = NULL;
			}
			free(insucc);
		}
		return;
	}
	if (r == tree->root)
	{
		tree->root = temp;
	}
	else if (parent->left == r)
		parent->left = temp;
	else if (parent->right == r)
		parent->right = temp;
}

void tree_inorder(Node *r)
{
	//TODO :  use printf to print inorder
	if (r != NULL)
	{
		tree_inorder(r->left);
		printf("%d ", r->data);
		tree_inorder(r->right);
	}
}

void tree_preorder(Node *r)
{
	//TODO :  use printf to print preorder
	if (r != NULL)
	{
		printf("%d ", r->data);
		tree_preorder(r->left);
		tree_preorder(r->right);
	}
}

void tree_postorder(Node *r)
{
	//TODO :  use printf to print postorder
	if (r != NULL)
	{
		tree_postorder(r->left);
		tree_postorder(r->right);
		printf("%d ", r->data);
	}
}

void postorder(Tree *t)
{
	//TODO
	tree_postorder(t->root);
}

void preorder(Tree *t)
{
	//TODO
	tree_preorder(t->root);
}

void inorder(Tree *t)
{
	//TODO
	tree_inorder(t->root);
}

void destroy(Node *r)
{
	//TODO
	if (r == NULL)
		return;
	else if (r->right == NULL && r->left == NULL)
	{
		free(r);
	}
	else
	{
		destroy(r->left);
		destroy(r->right);
		r->left = r->right = NULL;
		destroy(r);
	}
}

void tree_destroy(Tree *t)
{
	//TODO
	destroy(t->root);
}
