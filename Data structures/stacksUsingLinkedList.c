#include <stdio.h>
#include <stdlib.h> // for malloc , calloc and free

struct node *insert(struct node *top);
struct node *delete(struct node *top);
void display(struct node *top);

struct node
{
    int data;
    struct node *next;
};

void main()
{
    // top will always store the address of the newly created node
    int choice;
    struct node *top = NULL;
    do
    {
        printf("------Stack------");
        printf("\n1]Insert\n2]Delete\n3]Display\n4]Exit");
        printf("\nEnter your choice\n");
        printf("-----------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // after insertion of new node top will contain the address of the newly added node
            top = insert(top);
            break;

        case 2:
            // after deletion top will contain the address of the node added before the one which got deleted
            top = delete (top);
            break;

        case 3:
            display(top);
            break;
        }
    } while (choice != 4);
    // after every insertion or deletion top is going to have a changed address
}

// top will contain the address of the latest node added to the linked list .
// top will contain the address of the node at the beginning of the linked list
struct node *insert(struct node *top)
{

    // NewNode contains the address of the newly created node
    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));

    int n;
    printf("Enter the data to be inserted in the new node.\n");
    scanf("%d", &n);

    NewNode->data = n;
    NewNode->next = NULL; // our node is ready for insertion

    if (top == NULL)
    {
        // the list was empty , our newly created node is the first node
        top = NewNode;
    }
    else
    {
        NewNode->next = top;
        top = NewNode;
    }
    return top;
}

// top contains the address of the newly created node which is supposed to be deleted
struct node *delete(struct node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *ptr;
        ptr = top;
        // both ptr and top are pointing to the node which is to be deleted
        top = top->next;
        free(ptr);
        return top;
    }
}

// top contains the address of the node thats added to the list at the end
void display(struct node *top)
{
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        while (top != NULL)
        {
            printf("%d\n", top->data);
            top = top->next;
        }
    }
    // this function will print the elements of the stack from the top to bottom i.e. last ele to first ele
}
