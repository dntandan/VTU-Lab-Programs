#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
	char data;
	struct t_node *llink;
	struct t_node *rlink;
} TNODE;

void inorder(TNODE *root);
void preorder(TNODE *root);
void postorder(TNODE *root);
int search(TNODE *root, int key);
TNODE *getnode();
TNODE *insert(TNODE *root, int ele);
TNODE *delete (TNODE *root, int ele);
TNODE *findMin(TNODE *root);

void main()
{
	TNODE *root = NULL;
	int ch, flag;
	int ele, key;
	for (;;)
	{
		printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Delete\n7.Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the element to be inserted\n");
			scanf("%d", &ele);
			root = insert(root, ele);
			break;

		case 2:
			if (root == NULL)
				printf("Empty tree\n");
			else
			{
				printf("The contents are\n");
				inorder(root);
			}
			break;

		case 3:
			if (root == NULL)
				printf("Empty tree\n");
			else
			{
				printf("The contents are\n");
				preorder(root);
			}
			break;

		case 4:
			if (root == NULL)
				printf("Empty tree\n");
			else
			{
				printf("The contents are\n");
				postorder(root);
			}
			break;

		case 5:
			printf("Enter the element to be searched\n");
			scanf("%d", &key);
			flag = search(root, key);
			if (flag)
				printf("Found\n");
			else
				printf("Not Found\n");
			break;

		case 6:
			printf("Enter the element to be deleted\n");
			scanf("%d", &ele);
			root = delete (root, ele);
			break;

		case 7:
			exit(0);
		}
	}
}

TNODE *getnode()
{
	TNODE *temp = (TNODE *)malloc(sizeof(TNODE));
	if (temp == NULL)
	{
		printf("No Memory\n");
		exit(0);
	}
	return temp;
}

TNODE *insert(TNODE *root, int ele)
{
	TNODE *new = NULL;
	if (root == NULL)
	{
		new = getnode();
		new->data = ele;
		new->rlink = new->llink = NULL;
		return new;
	}
	if (ele > (root->data))
		root->rlink = insert(root->rlink, ele);
	if (ele < (root->data))
		root->llink = insert(root->llink, ele);
	return root;
}

void inorder(TNODE *root)
{
	if (root != NULL)
	{
		inorder(root->llink);
		printf("%d ", root->data);
		inorder(root->rlink);
	}
}

void preorder(TNODE *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->llink);
		preorder(root->rlink);
	}
}

void postorder(TNODE *root)
{
	if (root != NULL)
	{
		postorder(root->llink);
		postorder(root->rlink);
		printf("%d ", root->data);
	}
}

int search(TNODE *root, int key)
{
	if (root != NULL)
	{
		if (key == root->data)
			return 1;
		if (key > root->data)
			return (search(root->rlink, key));
		if (key < root->data)
			return (search(root->llink, key));
	}
	return 0;
}

TNODE *delete (TNODE *root, int ele)
{
	TNODE *temp = NULL;
	if (root == NULL)
		printf("Element not found\n");
	else if (ele < root->data)
		root->llink = delete (root->llink, ele);
	else if (ele > root->data)
		root->rlink = delete (root->rlink, ele);
	else
	{
		if (root->llink != NULL && root->rlink != NULL)
		{
			temp = findMin(root->rlink);
			root->data = temp->data;
			root->rlink = delete (root->rlink, temp->data);
		}
		else
		{
			temp = root;
			if (root->llink == NULL)
				root = root->rlink;
			else if (root->rlink == NULL)
				root = root->llink;
			free(temp);
		}
	}
	return root;
}

TNODE *findMin(TNODE *root)
{
	if (root == NULL)
		return NULL;

	if (root->llink != NULL)
		return findMin(root->llink);
	else
		return root;
}
