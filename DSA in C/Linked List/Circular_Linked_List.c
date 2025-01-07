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

    while (1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data (OR USE 0 to Terminate) : ");
        scanf("%d",&n);

        if(n == 0)
            break;

        newNode->data = n;
        newNode->next = NULL;

        if(head == NULL)
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
    if(head == 0)
    {
        printf("\nList is empty");
    }

    else
    {
        temp = head; // Start from the head of the list

        printf("Traversal of the circular linked list:\n");

        do
        {
            printf("%d ", temp->data);  // Print the data of the current node
            temp = temp->next;          // Move to the next node
            count++;                    // Increment the count of nodes visited
        } while (temp != head);         // Continue until we reach the head node again

        printf("\nNo. of nodes in the list: %d", count);          // Print the total count of nodes visited
    }
}