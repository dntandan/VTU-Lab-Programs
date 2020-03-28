#include <stdio.h>
#include <stdlib.h>
#define size 10

void cqinsert(char queue[], int *rear, int *count);
void cqdelete(char queue[], int *front, int *count);
void display(char queue[], int front, int count);

int main()
{
	char queue[size];
	int front = 0, rear = -1, ch, count = 0;
	for (;;)
	{
		printf("\n----Menu----\n");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter Your Choice ==> \t");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			if (count == size)
				printf("Queue is Full\n");
			else
				cqinsert(queue, &rear, &count);
			break;
		case 2:
			if (count == 0)
				printf("Queue is Empty\n");
			else
				cqdelete(queue, &front, &count);
			break;
		case 3:
			if (count == 0)
				printf("Queue is Empty\n");
			else
				display(queue, front, count);
			break;
		case 4:
			exit(0);
		}
	}
}

void cqinsert(char queue[], int *rear, int *count)
{
	char ele;
	printf("Enter a Character\n");
	scanf(" %c", &ele);
	*rear = (*rear + 1) % size;
	queue[*rear] = ele;
	(*count)++;
}

void cqdelete(char queue[], int *front, int *count)
{
	printf("Deleted Character is %c\n", queue[*front]);
	*front = (*front + 1) % size;
	(*count)--;
}

void display(char queue[], int front, int count)
{
	int i;
	printf("The Characters are\n");
	for (i = 0; i < count; i++)
	{
		printf("%c\t", queue[front]);
		front = (front + 1) % size;
	}
	printf("\n");
}
