#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    int x;
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
  
    printf("\nEnter data : ");
    scanf("%d",&x);

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void display()
{
    struct node *temp;
    temp = top;

    if( top == NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void peek()
{
    if( top == NULL)
    {
        printf("\nStck is Empty\n");
    }
    else
    {
      printf("%d is a peeked element in Stack",top->data);
    }
}

void pop()
{
    struct node *temp;
    temp = top;

    if( top == NULL)
    {
        printf("\nStck is Empty\n");
    }
    else
    {
        printf("%d is a poped element from stack\n",top->data);
        top = top->next;
        free(temp);
    }
}

int main()
{
    int choice ;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

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
            printf("\nExiting.....\n");
            return 0;

        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }    
}
