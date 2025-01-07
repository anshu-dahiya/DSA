#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void main()
{
    struct node *head, *newNode, *temp, *prevNode, *nextNode;
    int n, count = 0;
    head = NULL;
    
    while (1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data (o to terminate): ");
        scanf("%d",&n);

        if(n==0)
            break;

        newNode->data = n;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = temp = newNode;
        }

        else
        {
            temp->next = newNode;
            temp = newNode;
        }

    }  //end of while(1)

    //Traversing
    temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }
    
    printf("\nNo. of nodes in list are : %d\n",count);



    //Reversing the list
    temp = nextNode = head;
    prevNode = NULL;

    while (nextNode != NULL)
    {
        nextNode = nextNode->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
    }
    head = prevNode;
    

    
    //Traversing after Reversing
    temp = head;
    count = 0;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }
    
    printf("\nNo. of nodes in list after update : %d",count);

}