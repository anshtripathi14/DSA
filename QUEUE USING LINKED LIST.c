#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node* link;
};
struct node *front,*rear,*newptr,*save;
int main()
{
int opt,ele;
void insertion(int);
int deletion();
void traversing(struct node*);
front=NULL,rear=NULL;
printf("\nEnter main menu\n");
printf("\n1.INSERTION\n2.DELETION\n3.TRVAVERSING\n4.EXIT");
while(1)
{
printf("\n\nChoose any option: ");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Enter element: ");
scanf("%d",&ele);
insertion(ele);
break;
case 2:ele=deletion();
printf("\nThe deleted element is %d",ele);
break;
case 3:traversing(front);
break;
case 4:exit(0);
break;
default:printf("\nPlease choose a valid option(1/2/3/4/)");
break;
}
}
}
void insertion(int ele)
{
newptr=(struct node*)malloc(sizeof(struct node));
newptr->info=ele;
newptr->link=NULL;
if(front==NULL)
{
    front=newptr;
    rear=newptr;
}
    else
    {
    rear->link=newptr;
    rear=newptr;
    }
}
int deletion()
{
int ele;
if(front==NULL)
{
printf("Queue is underflow");
return(0);
}
else
{
ele=front->info;
save=front;
front=front->link;
free(save);
return(ele);
}
}
void traversing(struct node*front)
{
save=front;
while(save!=NULL)
{
printf("%d\t",save->info);
save=save->link;
}
}
