#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;


node *front = NULL;
node *rear = NULL;


void enqueue() {
    int data;
    node *temp = (node*)malloc(sizeof(node));
    
    if (temp == NULL) {
        printf("\nMemory allocation failed!\n");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;

    
    if (front == NULL && rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }

    printf("%d enqueued into the queue.\n", data);
}


void dequeue() {
    if (front == NULL) {
        printf("\nQueue is empty!\n");
        return;
    }

    node *temp = front;
    printf("Dequeued: %d\n", front->data);

    front = front->next;

  
    if (front == NULL)
        rear = NULL;

    free(temp);
}


void display() {
    if (front == NULL) {
        printf("\nQueue is empty!\n");
        return;
    }

    node *temp = front;
    printf("\nQueue contents (front to rear):\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice;
    do {
        printf("\n====== QUEUE MENU ======\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("\nExiting...\n"); break;
            default: printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
