#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};


void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
    
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    //Allocate memory of nodes in the linked list in Heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    //Link first and second nodes
    head->data = 7;
    head->next = second;

    
    //Link second and third nodes
    second->data = 14;
    second->next = third;

    
    //Terminate the list at third node
    third->data = 21;
    third->next = NULL;

    traversal(head);
    return 0;
}
