#include <stdlib.h>
#include <stdio.h>

struct node
{
    int info;
    struct node *forw;
};

struct node *head, *newptr, *save;

void create(int);
void insertatpos(int, int);
void display(struct node *);

int main()
{
    int ele, ans, n;
    head = NULL;

    while (1)
    {
        printf("\nEnter element: ");
        scanf("%d", &ele);
        create(ele);

        printf("Want to continue (Y/N)? ");
        scanf(" %c", &ans);
        if (ans == 'Y' || ans == 'y')
            continue;
        else
        {
            printf("\nSelect the element after which you want to insert your element in the list: ");
            scanf("%d", &n);
            printf("\nEnter the element you want to insert at that position: ");
            scanf("%d", &ele);
            insertatpos(ele, n);
            break;
        }
    }

    printf("Display elements forward:\n");
    display(head);

    return 0;
}

void create(int ele)
{
    newptr = (struct node *)malloc(sizeof(struct node));
    if (newptr == NULL)
    {
        printf("\nOut of memory\n");
        return;
    }

    newptr->info = ele;
    newptr->forw = NULL;

    if (head == NULL)
    {
        head = newptr;
        newptr->forw = head; 
    }
    else
    {
        save = head;
        while (save->forw != head)
        {
            save = save->forw;
        }
        save->forw = newptr;
        newptr->forw = head; 
    }
}

void insertatpos(int ele, int n)
{
    newptr = (struct node *)malloc(sizeof(struct node));
    if (newptr == NULL)
    {
        printf("\nOut of memory");
        return;
    }
    newptr->info = ele;
    newptr->forw = NULL;
    save = head;

    while (save->info != n && save->forw != head)
    {
        save = save->forw;
    }

    if (save->info != n)
        printf("\nElement not found");
    else
    {
        newptr->forw = save->forw;
        save->forw = newptr;
    }
}

void display(struct node *head)
{
    save = head;
    if (save == NULL)
    {
        printf("Circular linked list is empty\n");
        return;
    }

    do
    {
        printf("%d ", save->info);
        save = save->forw;
    } while (save != head);
}
