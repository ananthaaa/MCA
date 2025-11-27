#include<stdio.h>
#define SIZE 5

int main() {
int queue[SIZE], front = -1, rear = -1;
int choice, val, i;

while(1) {
printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter choice: ");
scanf("%d", &choice);

if(choice == 1) {
if(rear == SIZE - 1)
printf("Queue Overflow\n");
else {
printf("Enter value: ");
scanf("%d", &val);
if(front == -1) front = 0;
queue[++rear] = val;
}
}
else if(choice == 2) {
if(front == -1 || front > rear)
printf("Queue Underflow\n");
else {
printf("Dequeued: %d\n", queue[front++]);
if(front > rear) front = rear = -1;
}
}
else if(choice == 3) {
if(front == -1)
printf("Queue is empty\n");
else {
printf("Queue elements: ");
for(i = front; i <= rear; i++)
printf("%d ", queue[i]);
printf("\n");
}
}
else if(choice == 4) {
break;
}
else {
printf("Invalid choice\n");
}
}
return 0;
}



