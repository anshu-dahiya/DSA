#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void insertFront(int data);
void insertRear(int data);
void deleteFront();
void deleteRear();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                int data;
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(data);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void insertFront(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front = newNode;
    }
}

void insertRear(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }

    struct node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void deleteRear() {
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }

    if (front == rear) {
        deleteFront();
        return;
    }

    struct node* temp = front;

    while (temp->next != rear) {
        temp = temp->next;
    }

    free(rear);
    rear = temp;
    rear->next = NULL;
}

void display() {
    struct node* temp = front;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}