#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    int x;
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data : ");
    scanf("%d",&x);
    
    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;  
    }
    printf("\n%d is added in Queue\n",x);
}

void display()
{
    struct node *temp;
    
    if (front == NULL && rear == NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        temp = front;

        while (temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }   
    }   
}


void dequeue()
{
    struct node *temp;
    
    if (front == NULL && rear == NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        temp = front;
        printf("\n%d is deleted from Queue\n",front->data);
        front = front->next;
        free(temp);
    }   
}

void peek()
{
    struct node *temp;
    
    if (front == NULL && rear == NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\n%d is on peek of Queue\n",front->data);
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