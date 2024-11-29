#include <stdlib.h>
#include <stdio.h>

struct node
{
    int info;
    struct node *forw,* back;
};

struct node *start, *newptr, *save;

void create(int);
void insertatpos(int, int);
void displayForward(struct node *);

int main()
{
    int ele, ans, n;
    start = NULL;

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
    displayForward(start);

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
    newptr->back = NULL;

    if (start == NULL)
    {
        start = newptr;
    }
    else
    {
        save = start;
        while (save->forw != NULL)
        {
            save = save->forw;
        }
        save->forw = newptr;
        newptr->back = save;
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
    newptr->back = NULL;
    save = start;

    while (save->info != n && save != NULL)
    {
        save = save->forw;
    }

    if (save == NULL)
        printf("\nElement not found");
    else
    {
        newptr->forw = save->forw;
        newptr->back = save;
        if (save->forw != NULL)
        {
            save->forw->back = newptr;
        }
        save->forw = newptr;
    }
}

void displayForward(struct node *start)
{
    save = start;
    if (save == NULL)
    {
        printf("Doubly linked list is empty\n");
        return;
    }

    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->forw;
    }
}
