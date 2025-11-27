#include<stdio.h>

int main() {
 int size, element, found = 0;
 
 printf("Enter the size of the array: ");
 scanf("%d",&size);
 int arr[size];
 
 printf("Enter %d elements -\n", size);
 for (int i = 0; i<size; i++) {
 scanf("%d",&arr[i]);
 }
 
 printf("\n Enter the element to search: ");
 scanf("%d", &element);
 
 for (int i = 0; i < size; i++) {
 if(arr[i] == element) {
 found =1;
 printf("Element %d found at position %d",element, i + 1);
 break;
 }
 }
 
 if (!found) {
 printf("Element %d not found in the array", element);
 }

 return 0;
}
