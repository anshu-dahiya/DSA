#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void main()
{
    struct node *head, *newNode, *tail, *temp, *nextNode;
    int n, count = 0;
    head = NULL;

    while (1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data (OR use 0 to Terminate) : ");
        scanf("%d",&n);

        if(n==0)
            break;

        newNode->data=n;
        newNode->prev=NULL;
        newNode->next=NULL;

        if(head == NULL)
        {
            head = tail = newNode;
        }

        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }  //end of while(1)
    
    //Traversing
    temp = head;

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;

        count++;
    }
    
    printf("\nHead is : %d",head->data);
    printf("\nTail is : %d",tail->data);
    printf("\nNo. nodes in list are : %d\n",count);



    //Reversing
    if(head == NULL)
    {
        printf("\nList is Empty");
    }

    else
    {
        temp = head;

        while (temp != NULL)
        {
            nextNode = temp->next;
            temp->next = temp->prev;
            temp->prev = nextNode;
            temp = nextNode;
        }
        temp = head;
        head = tail;
        tail = temp;
    }

    
    //Traversing
    temp = head;

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
    printf("\nHead after reversing : %d",head->data);
    printf("\nTail after reversing : %d",tail->data);
    printf("\nNo. nodes in list after update : %d",count);
}




