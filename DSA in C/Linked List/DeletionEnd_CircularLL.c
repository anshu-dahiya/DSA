#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void main()
{
    struct node *head, *tail, *newNode, *temp;
    int n, count = 0; 
    head = NULL;

    while(1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data (OR USE 0 to Terminate) : ");
        scanf("%d",&n);

        if (n==0)
            break;

        newNode->data = n;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }

    }

    //Traversing
    temp = head; 

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);

    printf("\nNo. of Nodes in list are : %d\n",count);
    
    //Deletion at End
    if (head == tail) // If there is only one node
    {   
        free(head);

        head = NULL;
        tail = NULL;

        count--;
    }
    else
    {   // Traverse the list until the second last node
        temp = head; 

        while (temp->next != tail)
        {
            temp = temp->next;
        }
        
        // temp now points to the second last node
        temp->next = head;  // Set the next pointer of second last node to head
        free(tail);       // Free memory occupied by the last node
        tail = temp;        // Update tail to point to the new last node

        count--;

    }

    //Traversing after Deletion
    if (head == NULL)
    {
        printf("\nList Is Empty");
    }
    else
    {
        temp = head; 

        do
        {
            printf("%d ", temp->data);
            temp = temp->next;

        } while (temp != head);
    }
    
    printf("\nNo. of Nodes in List after update : %d",count);
}