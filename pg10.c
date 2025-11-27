#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the front.\n", value);
}


void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted at the end.\n", value);
}


void insertAtPosition(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("%d inserted at position %d.\n", value, position);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of range.\n", position);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", value, position);
}


void deleteFront() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("%d deleted from the front.\n", temp->data);
    free(temp);
}


void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp->next == NULL) {
        printf("%d deleted from the end.\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("%d deleted from the end.\n", temp->data);
    prev->next = NULL;
    free(temp);
}


void deleteValue(int value) {
    struct Node *temp = head, *prev = NULL;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (temp->data == value) {
        head = temp->next;
        printf("%d deleted from the list.\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    printf("%d deleted from the list.\n", value);
    free(temp);
}


void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, value, position;

while (1) {
printf("\n--- Singly Linked List Menu ---\n");
printf("1. Insert at Front\n");
printf("2. Insert at End\n");
printf("3. Insert at Specific Position\n");
printf("4. Delete from Front\n");
printf("5. Delete from End\n");
printf("6. Delete by Value\n");
printf("7. Display\n");
printf("8. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter value to insert at front: ");
scanf("%d", &value);
insertFront(value);
break;

case 2:
printf("Enter value to insert at end: ");
scanf("%d", &value);
insertEnd(value);
 break;

case 3:
printf("Enter value and position to insert: ");
scanf("%d %d", &value, &position);
insertAtPosition(value, position);
 break;

case 4:
deleteFront();
break;

case 5:
deleteEnd();
break;

case 6:
printf("Enter value to delete: ");
scanf("%d", &value);
deleteValue(value);
break;

case 7:
display();
break;

case 8:
exit(0);

default:
printf("Invalid choice! Try again.\n");
}
}
return 0;
}

