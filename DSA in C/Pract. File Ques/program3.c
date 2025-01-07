#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void insert(int data);
void delete();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                int data;
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void insert(int data) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Queue is full!\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = data;
}

void delete() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    int data = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }

    printf("Deleted data: %d\n", data);
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    int i = front;

    if (front <= rear) {
        while (i <= rear) {
            printf("%d -> ", queue[i]);
            i++;
        }
    } else {
        while (i <= SIZE - 1) {
            printf("%d -> ", queue[i]);
            i++;
        }

        i = 0;

        while (i <= rear) {
            printf("%d -> ", queue[i]);
            i++;
        }
    }

    printf("NULL\n");
}