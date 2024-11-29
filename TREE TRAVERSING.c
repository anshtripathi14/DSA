#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *left,*right;
}*btree;
int main()
{
    int ele,opt;
    char ans;
    void inorder(struct node*);
    void preorder(struct node*);
    void postorder(struct node*);
    struct node *insert(struct node*, int);
    void search(struct node*, int);
    btree=NULL;
    while(1)
    {
        printf("\nMain Menu");
        printf("\n1.Create \n2.In-order");
        printf("\n3.Pre-order \n4.Post-order");
        printf("\n5.Search \n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:while(1)
            {
            printf("\nEnter element: ");
            scanf("%d",&ele);
            btree=insert(btree,ele);
            fflush(stdin);
            printf("\nWant to continue(Y/N): ");
            scanf("%c",&ans);
            if(ans=='Y'||ans=='y')
            continue;
            else
            break;
            }
            break;
            case 2:printf("\nIn-order traversal: ");
            inorder(btree);
            break;
            case 3:printf("\nPre-order traversal: ");
            preorder(btree);
            break;
            case 4:printf("\nPost-order traversal: ");
            postorder(btree);
            break;
            case 5:printf("\nEnter element you want to search: ");
            scanf("%d",&ele);
            search(btree,ele);
            break;
            case 6:exit(0);
            default:printf("\nWrong choice");
        }
    }
}
struct node *insert(struct node *btree, int ele)
{
    if(btree==NULL)
    {
        btree=(struct node*)malloc(sizeof(struct node));
        btree->info=ele;
        btree->left=NULL;
        btree->right=NULL;
    }
    else
    if(ele<btree->info)
    btree->left=insert(btree->left,ele);
    else
    if(ele>btree->info)
    btree->right=insert(btree->right,ele);
    else
    printf("\nDuplicate node");
    return(btree);
}
void inorder(struct node *btree)
{
    if(btree!=NULL)
    {
        inorder(btree->left);
        printf("%d\t",btree->info);
        inorder(btree->right);
    }
}
void preorder(struct node *btree)
{
    if(btree!=NULL)
    {
    	printf("%d\t",btree->info);
        preorder(btree->left);
        preorder(btree->right);
    }
}
void postorder(struct node *btree)
{
    if(btree!=NULL)
    {
        postorder(btree->left);
        postorder(btree->right);
        printf("%d\t",btree->info);
    }
}
void search(struct node *btree,int ele)
{
    if(btree==NULL)
    printf("\nElement not found\n");
    else
    if(btree->info==ele)
    printf("\nElement found\n");
    else
    if(ele<btree->info)
    search(btree->left,ele);
    else
    search(btree->right,ele);
}
