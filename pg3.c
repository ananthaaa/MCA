#include <stdio.h>

int main() {
int arr[100];
int i, l, s, n;

printf("Enter the number of elements: ");
scanf("%d",&n);

printf("Enter %d element in the array: ");
for (i = 0; i < n; i++) {
printf("Element - %d : ", i);
scanf("%d", &arr[i]);

}

l = arr[0];
s = arr[0];

for (i = 1; i < n; i++) {
if(arr[i] > l) {
l = arr[i];
}
if(arr[i] < s) {

s = arr[i];
}
}

printf(" Largest Element is %d",l);
printf(" Smallest Element is %d",s);
return 0;
}
