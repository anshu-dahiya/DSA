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
    struct node *head, *newNode, *tail, *temp;
    int n, count = 0, pos ,i;
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
    
    printf("\nNo. nodes in list are : %d\n",count);



    //Deletion At Position 
    if(head == NULL)
    {
        printf("\nList is Empty");
    }

    else
    {
        printf("\nEnter the position where u want to delete : ");
        scanf("%d",&pos);
        
        if (pos <= 1  ||  pos > count)
        {
            printf("\n%d is Invalid Position \n",pos);
        }

        else
        {
            i=1;
            temp = head;

            while (i <= pos-1)
            {
                temp = temp->next;
                i++;
            }

            temp->prev->next = temp->next;     //Setting temp Next Node in the (next of temp Previous node)
            temp->next->prev = temp->prev;     //Setting temp Previous Node in the (prev of temp Next node)
            free(temp);
            
            count--;
        }
    }

    
    //Traversing After Deletion
    temp = head;

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
    printf("\nNo. nodes in list after update : %d",count);

}




