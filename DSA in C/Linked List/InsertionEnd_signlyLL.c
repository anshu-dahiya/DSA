#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void main()
{
    struct node *head, *newNode, *temp;
    int n;
    head = NULL;

    while(1)
    {
        printf("Enter the data (OR use 0 to Teminate) : ");
        scanf("%d",&n);

        if(n==0)
            break;

        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data=n;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;  
        }

        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }   // end of while(1)

    //Traversing
    temp = head;

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}