#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev, *next;
} *head = NULL;
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}
void insertBeg(int x) {
    struct Node* n = newNode(x);
    if (!head)
        head = n;
    else {
        n->next = head;
        head->prev = n;
        head = n;
    }
    printf("Element %d inserted at beginning.\n", x);
}
void insertEnd(int x) {
    struct Node *n = newNode(x), *t = head;
    if (!head) {
        head = n;
    } else {
        while (t->next)
            t = t->next;
        t->next = n;
        n->prev = t;
    }
    printf("Element %d inserted at end.\n", x);
}
void insertPos(int x, int pos) {
    if (pos <= 1 || !head) {
        insertBeg(x);
        return;
    }
    struct Node *t = head;
    int i;
    for (i = 1; i < pos - 1 && t->next; i++)
        t = t->next;
    struct Node* n = newNode(x);
    n->next = t->next;
    n->prev = t;
    if (t->next)
        t->next->prev = n;
    t->next = n;
    printf("Element %d inserted at position %d.\n", x, pos);
}
void delBeg() {
    if (!head) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    struct Node* t = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    printf("Element %d deleted from beginning.\n", t->data);
    free(t);
}
void delEnd() {
    if (!head) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    struct Node* t = head;
    if (!t->next) {
        printf("Element %d deleted from end.\n", t->data);
        free(t);
        head = NULL;
        return;
    }
    while (t->next)
        t = t->next;
    printf("Element %d deleted from end.\n", t->data);
    t->prev->next = NULL;
    free(t);
}
void delPos(int pos) {
    if (!head) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    if (pos <= 1) {
        delBeg();
        return;
    }
    struct Node* t = head;
    int i;
    for (i = 1; i < pos && t; i++)
        t = t->next;
    if (!t) {
        printf("Invalid position.\n");
        return;
    }
    printf("Element %d deleted from position %d.\n", t->data, pos);
    if (t->next)
        t->next->prev = t->prev;
    if (t->prev)
        t->prev->next = t->next;
    free(t);
}
void display() {
    struct Node* t = head;
    if (!t) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");
    while (t) {
        printf("%d ", t->data);
        if (!t->next) break;
        t = t->next;
    }

    printf("\nReverse: ");
    while (t) {
        printf("%d ", t->data);
        t = t->prev;
    }
    printf("\n");
}
int main() {
    int ch, val, pos;
    while (1) {
       printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\nEnter Your Choice: ");
        
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter The Value: ");
                scanf("%d", &val);
                insertBeg(val);
                break;
            case 2:
                printf("Enter The Value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 3:
                printf("Enter The Value and Position: ");
                scanf("%d%d", &val, &pos);
                insertPos(val, pos);
                break;
            case 4:
                delBeg();
                break;
            case 5:
                delEnd();
                break;
            case 6:
                printf("Enter Position: ");
                scanf("%d", &pos);
                delPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

