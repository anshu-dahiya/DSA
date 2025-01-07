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
    struct node *head, *tail, *newNode, *temp;
    int n, count = 0; 
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
    
    // Deletion at Beginning
    if (head != NULL)
    {
                        
        temp = head;        // Store the reference to the head node in temp
        head = head->next;   // Move head to the next node
        tail->next = head;    // Update the next pointer of tail to point to the new head
        
        free(temp); // Free the memory occupied by the previous head node
        
        count--; // Decrement the count of nodes
    }

    // Traversing after Deletion
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
