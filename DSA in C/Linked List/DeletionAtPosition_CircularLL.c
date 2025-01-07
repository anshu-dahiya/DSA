#include<stdio.h>
#include<stdlib.h>

// Define the structure of a node
struct node
{
    int data;
    struct node *next;
};

void main()
{
    struct node *head, *tail, *newNode, *temp, *prevNode;
    int n, count = 0, pos; 
    head = NULL;

    // Input data until user enters 0 to terminate
    while(1)
    {
        // Create a new node
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data (OR USE 0 to Terminate) : ");
        scanf("%d",&n);

        // Terminate loop if user enters 0
        if (n==0)
            break;

        // Assign data to the new node
        newNode->data = n;
        newNode->next = NULL;

        // If list is empty, make the new node as both head and tail
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }

        // If list is not empty, add the new node at the end and update tail
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // Traversing the circular linked list
    temp = head; 
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);

    printf("\nNo. of Nodes in list are : %d\n",count);
    
    
    // Deletion at a specific position
    printf("Enter the position where you want to delete : ");
    scanf("%d",&pos);

    if (pos <= 1 || pos > count)
    {
        printf("\nInvalid Position\n");
    }
    else
    {   
        int i = 1;
        temp = head;
        prevNode = NULL;

        // Traverse to the node at the specified position
        while (i < pos)
        {
            prevNode = temp;
            temp = temp->next;
            i++;
        }

        // Adjust the pointers to delete the node
        prevNode->next = temp->next;
        free(temp);

        count--;
         
    }
    

    // Traversing after Deletion
    if (head == NULL)
    {
        printf("\nList Is Empty");
    }
    else
    {
        temp = head; 

        // Traverse the updated circular linked list
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;

        } while (temp != head);
    }
    
    printf("\nNo. of Nodes in List after update : %d",count);
}
