#include<stdio.h>

#define n 5
int stack[n];
int top = -1;

void push()
{
    int x;

    printf("\nEnter the data to push : ");
    scanf("%d",&x);

    if(top == n-1)
    {
        printf("\n stack is overflow");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("\nElement %d pushed in stack\n",x);

    }
}

void pop()
{
    int item;

    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        item = stack[top];
        top--;
        printf("%d is poped from stack",item);
    }
}

void peek()
{
    int item;

    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("\n%d is peeked element in stack",stack[top]);
    }
}


void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for(i = top; i>=0; i--)
        {
            printf("%d ",stack[i]);
        }
    }
}   

int main()
{
    int choice, x;

    while (1) 
    {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        
        case 2:
            pop();
            break;
        
        case 3:
            peek();
            break;
        
        case 4:
            display();
            break;
        
        case 5:
            printf("\nExiting....\n");
            return 0;
            
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
}

