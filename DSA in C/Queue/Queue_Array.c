#include<stdio.h>

#define n 5
int queue[n];
int front = -1;
int rear = -1;

void enqueue()
{
    int x; 
    printf("\nEnter Data : ");
    scanf("%d",&x);

    if(rear == n-1)
    {
        printf("\nQueue is overflow\n");
    }

    else if (front == -1 && rear == -1 )
    {
        front = rear = 0;
        queue[rear] = x;
        printf("\n%d is added in Queue\n",x);
    }

    else
    {
        rear++;
        queue[rear] = x;
        printf("\n%d is added in Queue\n",x);
    } 
}


void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty\n");
    }

    else if (front == rear)
    {
        front = rear = -1;
    }

    else
    {
        printf("%d is deleted from Queue\n",queue[front]);
        front++;   
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty\n");
    }

    else
    {
        printf("\n%d is on peek in Queue\n",queue[front]);
    }   
}

void display()
{
    int i = front;

    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty\n");
    }

    else
    {
        while (i <= rear)
        {
            printf("%d ",queue[i]);
            i++;
        }       
    }
}



int main()
{
    int choice;

    while (1)
    {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
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