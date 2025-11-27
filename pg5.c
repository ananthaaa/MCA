#include <stdio.h>
#define SIZE 5

int main() {
int stack[SIZE], top = -1, choice, val;

while(1) {
printf("\n1.Push 2.Pop 3.Display 4.Peek 5.Exit\nEnter choice: ");
scanf("%d", &choice);

if(choice == 1) {
if(top == SIZE - 1) {
printf("Stack Overflow\n");
}
 else {
printf("Enter value to push: ");
scanf("%d", &val);
stack[++top] = val;
}
}
else if(choice == 2) {
if(top == -1)
printf("Stack Underflow\n");
else
printf("Popped: %d\n", stack[top--]);
}
else if(choice == 3) {
if(top == -1)
printf("Stack is empty\n");
else {
printf("Stack elements: ");
for(int i = top; i >= 0; i--)
printf("%d ", stack[i]);
printf("\n");
}
}
else if (choice == 4)
{
if (top == -1)
printf("Stack is empty. No top element to peek.\n");
else
printf("Top element is: %d\n", stack[top]);
}
else if(choice == 5) {
break;
}
else {
printf("Invalid choice\n");
}
}
return 0;
}

