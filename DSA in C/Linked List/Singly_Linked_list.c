#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void main()
{
    struct node *head, *newNode, *temp;
    int choice, count;
    head = NULL;
    
    while (choice)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data : ");
        scanf("%d",&newNode->data);
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
    
    printf("Do you want to continue? (0,1) : ");
    scanf("%d",&choice);
    }

    temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }
    

 printf("\nNo. of nodes in list are : %d",count);

    
}
