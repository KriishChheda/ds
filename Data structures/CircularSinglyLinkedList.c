#include <stdio.h>
#include <stdlib.h>

struct node *insert_start(struct node *start);
struct node *insert_end(struct node *start);
struct node *delete_start(struct node *start);
struct node *delete_end(struct node *start);
void display(struct node *start);

struct node
{
    int data;
    struct node *next;
};

void main()
{
    struct node *start = NULL;
    int choice;
    do
    {
        printf("-----circular single linked list-----\n");
        printf("\n1]Insert at the start");
        printf("\n2]Insert at the end");
        printf("\n3]Delete the first node");
        printf("\n4]Delete the last node");
        printf("\n5]Display");
        printf("\n6]Exit");
        printf("\nEnter your choice\n");
        printf("\n-----------------------------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = insert_start(start);
            break;

        case 2:
            start = insert_end(start);
            break;

        case 3:
            start = delete_start(start);
            break;

        case 4:
            start = delete_end(start);
            break;

        case 5:
            display(start);
            break;
        }
    } while (choice != 6);
}

// start contains the address of the first node of the list
struct node *insert_start(struct node *start)
{
    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));

    int val;
    printf("Enter the data item to be stored in the new node");
    scanf("%d", &val);

    NewNode->data = val;
    NewNode->next = start;

    if (start == NULL)
    {
        start = NewNode; // start points to the new node
        NewNode->next = start;
        return start;
    }
    else
    {
        struct node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        // now ptr points to last node of the list
        ptr->next = NewNode;
        // last node now points to the new node
        start = NewNode;
        return start;
    }
}

struct node *insert_end(struct node *start)
{
    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));

    int val;
    printf("Enter the data item to be stored in the new node");
    scanf("%d", &val);
    NewNode->data = val;

    if (start == NULL)
    {
        start = NewNode;
        NewNode->next = start;
        return start;
    }
    else
    {
        // its not the first insertion , start is not null
        struct node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        // ptr now points to the last node of the list

        ptr->next = NewNode;
        // now NewNode becomes the last node of the list

        NewNode->next = start;
        return start;
    }
}

// start contains the address of the node which is to be deleted
struct node *delete_start(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty");
        return start;
    }
    else
    {
        struct node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        // ptr now points to the last node of the list
        ptr->next = start->next;
        free(start);
        start = ptr->next;
        return start;
    }
}

struct node *delete_end(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty");
        return start;
    }

    else
    {
        struct node *preptr = start;
        struct node *ptr = start;
        while (ptr->next != start)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        // preptr points to the second last node of the list and ptr points to the last node of the list
        preptr->next = start;
        free(ptr);
        return start;
    }
}

// start contains the address of the first node of the list
void display(struct node *start)
{
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        struct node *ptr = start;
        while (ptr->next != start)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n%d", ptr->data);
    }
}