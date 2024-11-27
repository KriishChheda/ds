#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *insert_start(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_after(struct node *start);
struct node *insert_before(struct node *start);
struct node *delete_start(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_before(struct node *start);
void display(struct node *start);

void main()
{
    struct node *start = NULL;
    int choice;
    do
    {
        printf("-----Double Linked List-----");
        printf("\n1]Insert at the start");
        printf("\n2]Insert at the end");
        printf("\n3]Insert after a given node");
        printf("\n4]Insert before a given node");
        printf("\n5]Delete the first node");
        printf("\n6]Delete the last node");
        printf("\n7]Delete after a given node");
        printf("\n8]Delete before a given node");
        printf("\n9]Display");
        printf("\n10]Exit");
        printf("\n--------------------------\n");
        printf("\nEnter your choice\n");
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
            start = insert_after(start);
            break;

        case 4:
            start = insert_before(start);
            break;

        case 5:
            start = delete_start(start);
            break;

        case 6:
            start = delete_end(start);
            break;

        case 7:
            start = delete_after(start);
            break;

        case 8:
            start = delete_before(start);
            break;

        case 9:
            display(start);
            break;
        }
    } while (choice != 10);
}
// start contains the address of the first node of the existing linked list
struct node *insert_start(struct node *start)
{

    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));

    int n;
    printf("\nEnter the data to be stored in the new node\n");
    scanf("%d", &n);

    NewNode->data = n;
    NewNode->prev = NULL; // since its gonna be the first node
    NewNode->next = start;

    if (start == NULL)
    {
        start = NewNode;
        return start;
    }
    else
    {
        start->prev = NewNode;
        start = NewNode;
        return start;
    }
}

// start contains the address of the first node of the ll
struct node *insert_end(struct node *start)
{
    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));

    int n;
    printf("\nEnter the data to be stored in the new node\n");
    scanf("%d", &n);

    NewNode->data = n;
    NewNode->next = NULL; // since the newnode is going to be the last node of insertion

    if (start == NULL)
    {
        start = NewNode;
        return start;
    }

    struct node *ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    // after the execution of this while loop ptr points to the last node of the current ll
    ptr->next = NewNode;
    NewNode->prev = ptr;
    return start;
}
// start contains the address of the first node of the linked list
struct node *insert_after(struct node *start)
{
    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));

    int n;
    printf("\nEnter the data to be stored in the new node\n");
    scanf("%d", &n);
    NewNode->data = n;

    if (start == NULL)
    {
        start = NewNode;
        return start;
    }

    int num;
    printf("Enter the datafield of the node after which you want to insert");
    scanf("%d", &num);

    struct node *ptr = start;
    while (ptr->data != num)
    {
        ptr = ptr->next;
    }
    // ptr will point to the node after which we want to insert a new node

    NewNode->next = ptr->next;
    NewNode->prev = ptr;
    ptr->next->prev = NewNode;
    ptr->next = NewNode;

    return start;
}
struct node *insert_before(struct node *start)
{
    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));

    int n;
    printf("\nEnter the data to be stored in the new node\n");
    scanf("%d", &n);
    NewNode->data = n;

    if (start == NULL)
    {
        start = NewNode;
        return start;
    }

    int num;
    printf("Enter the datafield of the node before which you want to insert");
    scanf("%d", &num);

    struct node *ptr = start;
    while (ptr->data != num)
    {
        ptr = ptr->next;
    }
    // ptr contains the address of the node before which we want to insert a new node

    NewNode->prev = ptr->prev;
    NewNode->next = ptr;
    ptr->prev->next = NewNode;
    ptr->prev = NewNode;

    return start;
}

// its going to take the address of the first node of the linked list which is to be deleted.
struct node *delete_start(struct node *start)
{
    if (start == NULL)
    {
        printf("Linked List is empty");
        return start;
    }
    else
    {
        struct node *ptr = start;
        // both start and ptr are pointing to the first node of the linked list
        start = start->next;
        // start now points to the node which will be the first node of the new linked list
        start->prev = NULL;
        free(ptr);
        return start;
    }
}

struct node *delete_end(struct node *start)
{
    if (start == NULL)
    {
        printf("Linked List is empty");
        return start;
    }
    else
    {
        struct node *ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        // after the execution of this loop ptr will point to the node which is to be deleted
        // ptr->prev contains the address of the node which is going to be the last node after deletion
        ptr->prev->next = NULL;
        free(ptr);
        return start;
    }
}

struct node *delete_after(struct node *start)
{
    if (start == NULL)
    {
        printf("Linked List is empty");
        return start;
    }
    int num;
    printf("Enter the datafield of the node after which you want to delete");
    scanf("%d", &num);

    struct node *ptr = start;
    while (ptr->data != num)
    {
        ptr = ptr->next;
    }
    // ptr will point to the node after which we want to delete a node
    struct node *temp = ptr;
    // both temp and ptr are pointing to the node after which you want to delete
    temp = temp->next;
    // temp contains the address of the node to be deleted

    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return start;
}

struct node *delete_before(struct node *start)
{
    if (start == NULL)
    {
        printf("Linked List is empty");
        return start;
    }
    int num;
    printf("Enter the datafield of the node after which you want to delete");
    scanf("%d", &num);

    struct node *ptr = start;
    while (ptr->data != num)
    {
        ptr = ptr->next;
    }
    // ptr will point to the node before which we want to delete a node
    struct node *temp = ptr;
    temp = temp->prev;
    // temp contains the address of the node to be deleted
    ptr->prev = temp->prev;
    temp->prev->next = ptr;
    free(temp);
    return start;
}

void display(struct node *start)
{

    if (start == NULL)
    {
        printf("Linked List is empty");
    }

    while (start != NULL)
    {
        printf("\nData : %d", start->data);
        start = start->next;
    }
}