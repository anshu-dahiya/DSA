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
    int n, count, pos, i;
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
           tail->next = newNode;
           newNode->prev = tail;
           tail = newNode;  
        }
    }  //end of while(1)

    //Traversing
    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data); 
        temp = temp->next;
        
        count++;
    }
    
    printf("\nNo. of nodes in list are : %d",count);


    //Insertion At Pos
    printf("\nEnter the position where you want to add : ");
    scanf("%d",&pos);

    if(pos <= 1  ||  pos > count)
    {
        printf("\n%d is Invalid Position\n",pos);
    }

    else
    {   
        i=1;
        temp = head;

        while(i < pos-1)
        {
            temp = temp->next;
            i++;
        }

        printf("\nEnter the data you want to insert : ");
        scanf("%d",& newNode->data);

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        newNode->next->prev = newNode;         //prev of Next node of the Position were 

        count++;

    }

    // //Traversing After Insertion
    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\nNo. Nodes in List after update : %d",count);   
    
}