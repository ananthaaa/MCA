#include <stdio.h>
#define SIZE 5

int main() {
int queue[SIZE], front = -1, rear = -1;
int choice, val, i;

while (1) {
printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter choice: ");
scanf("%d", &choice);

if (choice == 1) { 
if ((rear + 1) % SIZE == front) {
printf("Queue Overflow (Circular Queue is Full)\n");
} else {
printf("Enter value: ");
scanf("%d", &val);
if (front == -1)
front = 0; 
rear = (rear + 1) % SIZE;
queue[rear] = val;
}
}

else if (choice == 2) {  
if (front == -1) {
printf("Queue Underflow (Circular Queue is Empty)\n");
} else {
printf("Dequeued: %d\n", queue[front]);
if (front == rear) {
                    
front = rear = -1;
} else {
front = (front + 1) % SIZE;
}
}
}

else if (choice == 3) {  
if (front == -1) {
printf("Queue is empty\n");
} else {
printf("Queue elements: ");
i = front;
while (i != rear) {
printf("%d ", queue[i]);
i = (i + 1) % SIZE;
}
printf("%d\n", queue[rear]); 
}
}

else if (choice == 4) {  
break;
}

else {
printf("Invalid choice\n");
}
}
return 0;
}

