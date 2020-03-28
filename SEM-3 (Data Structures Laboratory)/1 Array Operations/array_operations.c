#include <stdio.h>
#include <stdlib.h>
int n;
void read(int a[]);
void print(int a[]);
int delete(int a[],int pos);
void display(int a[]);
void insert(int a[],int pos,int ele);

int main()
{
    int a[10],ch,ele,pos;
    while(1)
    {
        printf("\nEnter your choice : \n 1. Add Array\n 2. Display Array\n 3. Insert Elements In Array\n 4. Delete Elements From Array\n 5. Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter number of elements of array ==> \t");
            scanf("%d",&n);
            read(a);
            break;
        case 2:
            print(a);
            break;
        case 3:
            printf("Enter element and position ==> \t");
            scanf("%d %d",&ele,&pos);
            insert(a,ele,pos);
            break;
        case 4:
            printf("Enter the position of the element ==> \t");
            scanf("%d",&pos);
            ele= delete(a,pos);
            printf("The deleted element is ==> \t %d",ele);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

void read(int a[])
{
    int i;
    printf("Enter the array elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void print(int a[])
{
    int i;
    printf("The array elements are : \n");
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
}

void insert(int a[],int ele,int pos)
{
    int i;
    for(i=n-1;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=ele;
    n++;
}

int delete(int a[],int pos)
{
    int i,ele;
    ele=a[pos-1];
    for(i=pos-1;i<n;i++)
    {
        a[i]=a[i+1];
    }
    n--;
    return ele;
}
