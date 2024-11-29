#include<stdio.h>
#include<conio.h>
void main()
{
int ar[100],i,n;
void display (int[],int);
clrscr();
printf("Enter size of an array\n");
scanf("%d",&n);
printf("\nEnter elements for an array\n");
for(i=0;i<=n-1;i++)
{
scanf("%d",&ar[i]);
}
printf("\nTraversed element:\n");
display (ar,n);
getch();
}
void display (int ar[],int n)
{
int i;
for(i=0;i<=n-1;i++)
{
printf("%d\t",ar[i]);
}
}

