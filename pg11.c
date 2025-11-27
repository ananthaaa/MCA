#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
void insertEnd(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;


if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
} else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
}
printf("Inserted %d\n", value);
}
void deleteValue(int value) {
struct Node* temp = head;
while (temp != NULL && temp->data != value)
        temp = temp->next;
if (temp == NULL) {
printf("Value %d not found.\n", value);
return;
}
if (temp->prev == NULL) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
} 
else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
}

free(temp);
printf("Deleted %d\n", value);
}
void displayForward() {
struct Node* temp = head;
if (temp == NULL) {
        printf("List is empty.\n");
        return;
}
printf("Forward: ");
while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
}
printf("NULL\n");
}
void displayBackward() {
struct Node* temp = head;
if (temp == NULL) {
printf("List is empty.\n");
return;
}
while (temp->next != NULL)
        temp = temp->next;
printf("Backward: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->prev;
}
printf("NULL\n");
}


int main() {
int choice, value;
while (1) {
printf("\n--- Doubly Linked List Menu ---\n");
printf("1. Insert at End\n2. Delete by Value\n3. Display Forward\n4. Display Backward\n5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to insert: ");
scanf("%d", &value);
insertEnd(value);
break;
case 2:
printf("Enter value to delete: ");
scanf("%d", &value);
deleteValue(value);
break;
case 3:
displayForward();
break;
case 4:
displayBackward();
break;
case 5:
exit(0);

default:
printf("Invalid choice! Try again.\n");
}
}
return 0;
}

