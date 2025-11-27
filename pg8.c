#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

node *head = NULL;

void push() {
    int data;
    node *temp;
    temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("\nMemory allocation failed\n");
        return;
    }
    printf("\nEnter value: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = head;
    head = temp;
    printf("Pushed %d onto the stack.\n", data);
}

void pop() {
    if (head == NULL) {
        printf("\nStack is empty!\n");
        return;
    }
    node *temp = head;
    printf("Popped %d from the stack.\n", head->data);
    head = head->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("\nStack is empty!\n");
        return;
    }
    node *temp = head;
    printf("\nStack contents (top to bottom):\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}


