#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char usn[10];
	char name[15];
	char branch[2];
	int sem;
	long int phno;
	struct node *link;
} NODE;

typedef struct head_node
{
	int count;
	struct node *link;
} HEAD;

NODE *getNode();
void insfront(HEAD *head);
void insrear(HEAD *head);
void delfront(HEAD *head);
void delrear(HEAD *head);
void display(HEAD *head);

int main()
{
	HEAD *head = (HEAD *)malloc(sizeof(HEAD));
	int ch;
	head->count = 0;
	head->link = NULL;
	for (;;)
	{
		printf("\n----Menu----\n");
		printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
		printf("For Stack Choose 2,4 and 5 options\nSelect The Option ==> \t");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			insfront(head);
			break;
		case 2:
			insrear(head);
			break;
		case 3:
			if (head->link == NULL)
				printf("List Empty\n");
			else
				delfront(head);
			break;
		case 4:
			if (head->link == NULL)
				printf("List Empty\n");
			else
				delrear(head);
			break;
		case 5:
			if (head->link == NULL)
				printf("List Empty\n");
			else
				display(head);
			break;
		case 6:
			exit(0);
		}
	}
}

NODE *getNode()
{
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	if (temp == NULL)
	{
		printf("No Memory\n");
		exit(0);
	}
	return temp;
}

void insfront(HEAD *head)
{
	NODE *new = getNode();
	(head->count)++;
	printf("Enter Details such as USN Name Branch Semester PhNo\n");
	scanf("%s%s%s%d%ld", (new->usn), (new->name), (new->branch), &(new->sem), &(new->phno));
	new->link = head->link;
	head->link = new;
	return;
}

void insrear(HEAD *head)
{
	NODE *new = getNode();
	NODE *temp = head->link;
	(head->count)++;
	printf("Enter Details such as USN Name Branch Semester PhNo\n");
	scanf("%s%s%s%d%ld", (new->usn), (new->name), (new->branch), &(new->sem), &(new->phno));
	new->link = NULL;
	if (temp == NULL)
	{
		head->link = new;
		return;
	}
	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = new;
	return;
}

void delfront(HEAD *head)
{
	NODE *temp = head->link;
	(head->count)--;
	printf("Deleted Record is \n");
	printf("%s\t%s\t%s\t%d\t%ld\n", (temp->usn), (temp->name), (temp->branch), (temp->sem), (temp->phno));
	head->link = temp->link;
	return;
}

void delrear(HEAD *head)
{
	NODE *previous = NULL, *present = head->link;
	(head->count)--;
	if (present->link == NULL)
	{
		head->link = NULL;
	}
	else
	{
		while (present->link != NULL)
		{
			previous = present;
			present = present->link;
		}
		previous->link = NULL;
	}
	printf("Deleted Record is \n");
	printf("%s\t%s\t%s\t%d\t%ld\n", (present->usn), (present->name), (present->branch), (present->sem), (present->phno));
	free(present);
	return;
}

void display(HEAD *head)
{
	NODE *temp = head->link;
	printf("Total Records are %d\n", head->count);
	printf("USN\tName\t\tBranch\tSem\tPhNo\n");
	while (temp != NULL)
	{
		printf("%s\t%s\t\t%s\t%d\t%ld\n", (temp->usn), (temp->name), (temp->branch), (temp->sem), (temp->phno));
		temp = temp->link;
	}
}
