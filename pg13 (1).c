#include <stdio.h>
void main()
{
int a[]={0,0,0,0,0,0,0,0,0,0,0},b[]={0,0,0,0,0,0,0,0,0,0,0},i,j,s1,s2,f,g;
printf("\nEnter array 1 size : ");
scanf("%d",&s1);
printf("\nEnter elements : \n");
for(i=0;i<s1;i++)
{
scanf("%d",&f);
a[f]=1;
}
printf("Enter array 2 size : ");
scanf("%d",&s2);
printf("\nEnter elements : \n");
for(j=0;j<s2;j++)
{
scanf("%d",&g);
b[g]=1;
}
printf("\n Bitstring of 1st array : ");
for(i=0;i<11;i++)
{
printf("%d ",a[i]);
}
printf(" \n \n Bitstring of 2nd array : ");
for(j=0;j<11;j++)
{
printf("%d ",b[j]);
}
printf("\n Union Operation :");
for(i=0;i<11;i++)
{
printf("%d", a[i]|b[i]);
}
printf("\n Intersection Operation :");
for(i=0;i<11;i++)
{
printf("%d", a[i]&b[i]);
}
printf("\n Complement of Array 1 :");
for(i=0;i<11;i++)
{
printf("%d", !a[i]);
}
printf("\n Complement of Array 2 :");
for(i=0;i<11;i++)
{
printf("%d", !b[i]);
}
}


