#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtEnd(struct node **head, struct node **tail, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (*head == NULL)
    {
        *head = *tail = newNode;
        (*tail)->next = *head;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
        (*tail)->next = *head;
    }
}

void insertAtBeginning(struct node **head, struct node **tail, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (*head == NULL)
    {
        *head = *tail = newNode;
        (*tail)->next = *head;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
        (*tail)->next = *head;
    }
}

void insertAtPosition(struct node **head, int pos, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (pos <= 1)
    {
        printf("Position is invalid.\n");
        return;
    }

    struct node *temp = *head;
    int count = 1;
    while (count < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Position is out of range.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void displayList(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("Traversal of the circular linked list:\n");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}



int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int choice, data, pos;

    do
    {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtBeginning(&head, &tail, data);
            break;

        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(&head, &tail, data);
            break;

        case 3:
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtPosition(&head, pos, data);
            break;

        case 4:
            displayList(head);
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}