#include <stdio.h>
#include <stdlib.h>
struct tnode
{
	int data;
	struct tnode *left;
	struct tnode *right;
};
void inorder(struct tnode *);
void preorder(struct tnode *);
void postorder(struct tnode *);
void insert(struct tnode **, int);
int count(struct tnode *);
int leafcount(struct tnode *);
int height(struct tnode *);
struct tnode *rinsert(struct tnode *, int);
struct tnode *tdelete(struct tnode *, int);
int search(struct tnode *, int);
int rsearch(struct tnode *, int);
int minimum(struct tnode *);
int maximum(struct tnode *);
void main()
{
	struct tnode *root;
	int ch, num, k, n;
	root = NULL;
	while (1)
	{
		printf("\n1.Insert");
		printf("\n2.Preorder");
		printf("\n3.Postorder");
		printf("\n4.Inorder");
		printf("\n5.No. of nodes");
		printf("\n6.No. of Leaf nodes");
		printf("\n7.Height of a tree");
		printf("\n8.delete a node");
		printf("\n9..recursively insert..");
		printf("\n10..search..");
		printf("\n11..search using recursion..");
		printf("\n13.find smallest");
		printf("\n14.find largest");
		printf("\n15..exit");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the element");
			scanf("%d", &num);
			insert(&root, num);
			break;
		case 2:
			preorder(root);
			break;
		case 3:
			postorder(root);
			break;
		case 4:
			inorder(root);
			break;
		case 5:
			k = count(root);
			printf("\nthe number of nodes=%d", k);

			break;
		case 6:
			k = leafcount(root);
			printf("\nthe number of nodes=%d", k);

			break;
		case 7:
			k = height(root);
			printf("\nthe height of tree=%d", k);

			break;
		case 8:
			printf("Enter the node to be deleted\n");
			scanf("%d", &num);
			root = tdelete(root, num);
			break;
		case 9:
			printf("Enter the element");
			scanf("%d", &num);
			root = rinsert(root, num);
			break;

		case 10:
			printf("Enter the element");
			scanf("%d", &num);
			int k = search(root, num);
			if (k)
				printf("Key found\n");
			else
				printf("Not found..\n");
			break;

		case 11:
			printf("Enter the element");
			scanf("%d", &num);
			int m = rsearch(root, num);
			if (m)
				printf("Key found\n");
			else
				printf("Not found..\n");
			break;
		case 13:
			n = minimum(root);
			printf("\nThe smallest element = %d\n", n);
			break;
		case 14:
			n = maximum(root);
			printf("\nthe largest element = %d\n", n);
			break;
		case 15:
			exit(0);
		}
	}
}

void preorder(struct tnode *t)
{
	if (t != NULL)
	{
		printf("%d ", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

void inorder(struct tnode *t)
{
	if (t != NULL)
	{
		inorder(t->left);
		printf("%d ", t->data);
		inorder(t->right);
	}
}

void postorder(struct tnode *t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d ", t->data);
	}
}

//function to search for key in a BST
/*int search(struct tnode *t, int key)
	{
	  struct tnode *curr;
	
	curr=t;
	while(curr!=NULL)
	{
		if(key==curr->data)
	                 	return 1;
		if(key < curr->data)
		  curr=curr->left;
		else
		  curr=curr->right;
	}
	return 0;
	}*/

int search(struct tnode *t, int key)
{
	struct tnode *curr;

	curr = t;
	while ((curr != NULL) && (key != curr->data))
	{
		if (key < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (curr != NULL)
		return 1;
	return 0;
}

int rsearch(struct tnode *t, int key)
{
	if (t == NULL)
		return 0;
	if (key == t->data)
		return 1;
	if (key < t->data)
		return (rsearch(t->left, key));
	else
		return (rsearch(t->right, key));
}

struct tnode *rinsert(struct tnode *t, int x)
{
	struct tnode *temp;

	if (t == NULL)
	{
		temp = (struct tnode *)malloc(sizeof(struct tnode));
		temp->data = x;
		temp->left = temp->right = NULL;

		return temp;
	}

	if (x < t->data)
		t->left = rinsert(t->left, x);
	else
		t->right = rinsert(t->right, x);
	return t;
}

int minimum(struct tnode *t)
{
	while (t->left != NULL)
		t = t->left;
	return (t->data);
}

int maximum(struct tnode *t)
{
	while (t->right != NULL)
		t = t->right;
	return (t->data);
}

int height(struct tnode *t)
{
	int l, r;
	if (t == NULL) //empty tree
		return -1;
	//one node tree
	if ((t->left == NULL) && (t->right == NULL))
		return 0;
	l = height(t->left);  //height of left subtree
	r = height(t->right); //height of right subtree
	if (l > r)
		return 1 + l;
	else
		return 1 + r;
}

int count(struct tnode *t)
{
	if (t == NULL) //empty tree
		return 0;
	int l = count(t->left);	 //nodes in the left subtree
	int r = count(t->right); //nodes in right subtree
	return (l + r + 1);
}

int leafcount(struct tnode *t)
{
	if (t == NULL) //empty tree
		return 0;
	if ((t->left == NULL) && (t->right == NULL)) //one node tree
		return 1;
	int l = leafcount(t->left);
	int r = leafcount(t->right);
	return (l + r);
}

struct tnode *tdelete(struct tnode *t, int key)
{

	struct tnode *curr, *temp, *prev, *p, *q;
	prev = NULL;
	curr = t;
	while ((curr != NULL) && (curr->data != key))
	{
		prev = curr;
		if (key < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (curr == NULL)
	{
		printf("Key Not found..\n");
		return t;
	}

	// if node has one subtree or no subtrees
	if ((curr->left == NULL) || (curr->right == NULL))
	{
		if (curr->left == NULL)
			q = curr->right;
		else
			q = curr->left;

		//deleting root with one subtree
		if (prev == NULL)
		{
			free(curr);
			return q;
		}
		if (curr == prev->left)
			prev->left = q;
		else
			prev->right = q;
		free(curr);
	}
	else
	{
		//two subtrees present
		p = NULL; //parent of inorder successor
		temp = curr->right;
		while (temp->left != NULL)
		{
			p = temp;
			temp = temp->left;
		}
		curr->data = temp->data;
		if (p != NULL)
			p->left = temp->right;
		else
			curr->right = temp->right;
		free(temp);
	}
	return (t);
}

void insert(struct tnode **t, int x)
{

	struct tnode *temp;
	struct tnode *prev, *curr;

	temp = (struct tnode *)malloc(sizeof(struct tnode));
	temp->data = x;
	temp->left = temp->right = NULL;

	if (*t == NULL) //empty tree
		*t = temp;	//copy temp into root
	else
	{
		curr = *t;
		prev = NULL;

		while (curr != NULL)
		{
			prev = curr;
			if (x < curr->data)
				curr = curr->left; //move left
			else
				curr = curr->right;
		}
		if (x < prev->data)
			prev->left = temp;
		else
			prev->right = temp;
	}
}
