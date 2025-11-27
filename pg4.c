#include <stdio.h>
int main()
{
int N,M,O, temp;
int i,j,A[100], B[100],C[100];
printf("Enter the size of the first array");
scanf("%d", &N);
printf("Enter the elements of the first array");
for (i=0;i<N; i++)
scanf("%d", &A[i]);
printf("Enter the size of the second array");
scanf("%d", &M);
printf("Enter the elements of the second array");
for (i=0;i<M; i++)
scanf("%d", &B[i]);
O=N+M;
for (i=0;i<N; i++)
C[i]=A[i];
for (i=0;i<M; i++)
C[i+N]=B[i];
for (i=0;i<O;i++) {
for(j=i+1;j<O;j++){
if(C[i] < C[j]){
temp=C[i];
C[i]=C[j];
C[j]=temp;
}
}
}
printf("Merged array after sorting");
for (i=0; i<O;i++)
printf("%d ",C[i]);
return 0;
}
