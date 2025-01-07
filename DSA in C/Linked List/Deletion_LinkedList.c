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


struct Node * deleteFirst(struct Node *head )
{
    struct Node *ptr =  head;
    
    head = head->next;
    free(ptr);
    return head;
}


struct Node * deleteAtIndex(struct Node *head, int index)
{
    struct Node *p =  head;
    struct Node *q =  head->next;
    
    for(int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}


struct Node * deleteAtEnd(struct Node *head)
{
    struct Node *p =  head;
    struct Node *q =  head->next;
    
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}


// Case 4 : Deleting the element with given value from the linked list
struct Node * deleteAtValue(struct Node *head, int value)
{
    struct Node *p =  head;
    struct Node *q =  head->next;
    
    while(q->data != value   &&   q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocate memory of nodes in the linked list in Heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    //Link first and second nodes
    head->data = 7;
    head->next = second;

    
    //Link second and third nodes
    second->data = 14;
    second->next = third;

    
    //Link third and fourth nodes
    third->data = 21;
    third->next = fourth;


    //Terminate the list at fourth node
    fourth->data = 28;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    traversal(head);

    //head = deleteFirst(head);
    //head = deleteAtIndex(head, 2);
    // head = deleteAtEnd(head);
    head = deleteAtValue(head, 14);
    printf("\nLinked list after deletion\n");
    traversal(head);

    return 0;
}
