#include <stdio.h>
#include <ctype.h>
int stack[20];
int top = -1;
void push(int ele);
int pop();
void eval(char post[]);

int main()
{
  while(1){
    char post[20];
    printf("\nEnter the postfix expression ==> \t");
    scanf("%s",post);
    eval(post);
    printf("The evaluated answer is ==> %d\n",pop());
  }
}

void push(int ele)
{
    stack[++top]=ele;
}

int pop()
{
    return (stack[top--]);
}

void eval(char post[])
{
    char ch;
    int i,b,a;
    for(int i=0;post[i];i++)
    {
        ch = post[i];
        if(isdigit(ch))
            push(ch-'0');
        else
        {
            b=pop();
            a=pop();
            switch(ch)
            {
                case '+': push(a+b);
                    break;
                case '-': push(a-b);
                    break;
                case '*': push(a*b);
                break;
                case '/':
                    if(b==0){
                        printf("Divide by zero error\n");
                    }else
                    {
                        push(a/b);
                    }
                    break;
                default: printf("Invalid expression\n");
            }
        }

    }
}
