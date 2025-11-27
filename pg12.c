#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *left, *right;
};
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct node* insert(struct node* root, int value) {
    if (root == NULL) 
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
}
}
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
}
}
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
}
}
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct node* delete(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        
     if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
} else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
}      
struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
}
return root;
}

int main() {
struct node* root = NULL;
int choice, value;
struct node* temp;
while (1) {
printf("\n--- Binary Search Tree ---\n");
printf("1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Delete\n7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
 case 1:
printf("Enter value to insert: ");
scanf("%d", &value);
root = insert(root, value);
break;
 case 2:
printf("Inorder: ");
inorder(root);
printf("\n");
break;
case 3:
printf("Preorder: ");
preorder(root);
printf("\n");
break;
case 4:
printf("Postorder: ");
postorder(root);
printf("\n");
break;
case 5:
printf("Enter value to search: ");
scanf("%d", &value);
temp = search(root, value);
if (temp != NULL)
printf("Value found!\n");
else
printf("Value not found!\n");
break;
case 6:
printf("Enter value to delete: ");
scanf("%d", &value);
root = delete(root, value);
printf("Node deleted (if found).\n");
break;
case 7:
printf("Exiting...\n");
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}

