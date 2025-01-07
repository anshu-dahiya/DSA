#include<Stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertEND(struct node *head,struct node *tail,int data)
{
    struct node *newNode;
    
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
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



void insertBeginning(struct node *head,struct node *tail,int data)
{
    struct node *newNode;
    
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
        tail->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void insertPosition(struct node *head,int data,int pos)
{
    struct node *newNode, *temp;
    int count = 0;
    
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    temp = head;
    do
    {
        temp = temp->next;
        count++;
    }while(temp != head);

    if (pos <= 1  ||  pos > count)
    {
        printf("Position is Invalid\n");
    }

    else
    {
        temp = head; 
        int i = 1;
        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next = newNode;  
    }   
}

void display(struct node *head )
{
    struct node *temp;
    int count = 0;

    if (head == NULL)
    {
        printf("List is Empty\n");
    }

    else
    {
        temp = head;

        printf("Traversal of Circular List\n");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;

            count++;
        }while(temp != head);

        printf("\nNo. of Nodes in List are : %d",count);
        
    }
}


int main()
{
    struct node *head, *tail;
    int data, pos, choice;
    head = NULL;
    tail = NULL;

    do
    {
        printf("\n1. Insert At Beginning");
        printf("\n2. Insert At End");
        printf("\n3. Insert At Position");
        printf("\n4. Display");
        printf("\n0. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1 :
            printf("Enter the data to insert : ");
            scanf("%d", &data);
            insertBeginning(&head, &tail, data);
            break;
        
        case 2 :
            printf("Enter the data to insert : ");
            scanf("%d", &data);
            insertEND(&head, &tail, data);
            break;
        
        case 3 :
            printf("Enter the data to insert : ");
            scanf("%d", &data);
            printf("Enter the position : ");
            scanf("%d", &pos);
            insertPosition(&head, data, pos);
            break;
        
        case 4 :
            display(head);
            break;
        
        case 0 :
            printf("Exiting....");
            break;
        

        default:
            break;
        }
    }
    while(choice != 0);
    
}

