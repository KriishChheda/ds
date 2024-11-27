#include <stdio.h>
#include <stdlib.h>

// front will contain the address of the first node
// rear will contain the address of the last node
struct node *front = NULL;
struct node *rear = NULL;

struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node *ptr);
struct node *delete(struct node *ptr);
void peek(struct node *ptr);

void main()
{
    int choice;
    do
    {
        printf("\n------Linear Queue------\n");
        printf("\n1]Insert\n2]Delete\n3]Peek\n4]Exit");
        printf("Enter your choice");
        printf("\n----------------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            rear = insert(rear);
            break;

        case 2:
            front = delete (front);
            break;

        case 3:
            peek(front);
            break;
        }
    } while (choice != 4);
}

// ptr will contain the address present in the rear
struct node *insert(struct node *ptr)
{
    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));
    int n;
    printf("\nEnter the data to be stored in the new node\n");
    scanf("%d", &n);

    NewNode->data = n;
    NewNode->next = NULL;

    if (ptr == NULL)
    {
        // our ptr/Front was pointing to nothing
        front = NewNode;
        rear = NewNode;
        // both front and rear are pointing to the first node
        return rear;
    }

    else
    {
        // rear contains the adddress of the last node
        rear->next = NewNode;
        rear = NewNode;
        return rear;
    }
}

// we'll pass the address of the first node to ptr
struct node *delete(struct node *ptr)
{

    struct node *temp = ptr;
    if (ptr == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The element to be deleted is:\n");
        printf("%d", ptr->data);

        // temp and ptr are both pointing to the first node
        ptr = ptr->next;
        free(temp);
        return ptr;
    }
}
void peek(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("Queue is empty");
    }

    else
    {
        printf("\nThe first element is :\n");
        printf("%d", ptr->data);
    }
}
