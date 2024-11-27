#include <stdio.h>
#include <stdlib.h>

// every node will have three parts , the datafield , priority , pointer to the next node
struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *insert(struct node *start);
struct node *delete(struct node *start);
void display(struct node *start);

void main()
{
    struct node *start = NULL;
    int choice;
    do
    {
        printf("\n---Priority Queue---\n");
        printf("1]insert\n2]delete\n3]display\n4]exit\n");
        printf("Enter your choice\n");
        printf("\n--------------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = insert(start);
            break;

        case 2:
            start = delete (start);
            break;

        case 3:
            display(start);
            break;
        }
    } while (choice != 4);
}

// this is the most important function of the entire code
// start contains the address of the first node
struct node *insert(struct node *start)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    int n, pri;
    printf("\nEnter data to be stored in the new node:");
    scanf("%d", &n);
    printf("\nEnter the priority to be assigned in the new node:");
    scanf("%d", &pri);

    ptr->data = n;
    ptr->priority = pri;

    if (start == NULL || ptr->priority <= start->priority)
    {
        // in this case the new node is going to be the first node of the LL
        // in this case the address stored in start is going to change too
        // the new node is of a higher priority
        ptr->next = start;
        start = ptr;
    }
    else
    {
        struct node *p;
        p = start; // p is pointing to the first node
        while (p->next != NULL && p->next->priority <= pri)
        {
            p = p->next;
        }
        // finally p contains the address of the node after which we want to insert a new node
        ptr->next = p->next;
        p->next = ptr;
    }
    return start;
}

struct node *delete(struct node *start)
{
    if (start == NULL)
    {
        printf("Queue is empty");
    }

    else
    {
        struct node *p;
        p = start;
        // both p and start are pointing to the first node of the LL

        start = start->next;
        free(p);
    }
    return start;
}

void display(struct node *start)
{
    struct node *ptr = start; // ptr contains the address of the first node
    if (start == NULL)
    {
        printf("Queue is empty");
    }

    else
    {
        while (ptr != NULL)
        {
            printf("Data : %d\n", ptr->data);
            printf("Priority : %d\n", ptr->priority);
            ptr = ptr->next;
        }
    }
}
