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
    int n, count, pos, i;
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
    
    printf("\nNo. of nodes in list are : %d",count);


    //Insertion in Between
    printf("\nEnter the postion where you want to add item : ");
    scanf("%d",&pos);

    if(pos <=1  || pos > count)
    {
        printf("%d is Invalid Position \n",pos);
    }    

    else
    {
        i=1;
        temp = head;

        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }

        printf("\nEnter the item to add in between : ");
        scanf("%d",&newNode->data);

        newNode->next = temp->next;
        temp->next = newNode;

        count++;
    }


    //Traversing after insertion
    temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
    printf("\nNo. of nodes in list after upadate : %d",count);
    
}
