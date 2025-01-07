#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void main()
{
    struct node *head, *tail, *newNode, *temp;
    int n, count;
    head = NULL;

    while (1)
    {
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter the Data (OR USE 0 to terminate) : ");
        scanf("%d",&n);

        if(n==0)
            break;

        newNode->data = n;
        newNode->prev = NULL;
        newNode->next = NULL;
        
        if(head == NULL)
        {
            head  = tail = newNode;
        }

        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }   //end of while(1)

    //Traversing
    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data); 
        temp = temp->next;
        
        count++;
    }
    
    printf("\nNo.of nodes in list are : %d",count);


}