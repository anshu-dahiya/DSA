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


struct Node * insertAtBeginning(struct Node *head , int data)
{
    struct Node *ptr =  (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}


struct Node * insertAtEnd(struct Node *head , int data)
{
    struct Node *ptr =  (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node * p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next =NULL;
    return head;
}


struct Node * insertAfterNode(struct Node *head ,struct Node *prevNode, int data)
{
    struct Node *ptr =  (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
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

    printf("Linked list before insertion\n");
    traversal(head);
    head = insertAtBeginning(head, 4);
    insertAtEnd(head,56);
    head = insertAfterNode(head, second, 18);
    printf("\nLinked list after insertion\n");
    traversal(head);

    return 0;
}
