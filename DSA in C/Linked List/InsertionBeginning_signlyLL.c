#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void main()
{ 
    struct node *head, *newnode, *temp;
    int n;
    head = NULL;
    
    while (1)
    {
        printf("Enter data (o to terminate): ");
        scanf("%d",&n);

        if(n==0)
            break;

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = n;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        
        else
        {   
            newnode->next = head;
            head = newnode;
        }
    }  // end while(1)

    //traversing
    temp = head;

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
    
    

    



