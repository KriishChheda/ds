#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // next is a pointer which stores the address of a struct node datatype variable
};

void linkedListTraversal(struct node *ptr);
struct node *insertAtBeginning(struct node *ptr);
void insertAtEnd(struct node *ptr);
void insertAfterGivenNode(struct node *ptr, int val);
void insertBeforeGivenNode(struct node *preptr, struct node *ptr, int val);
struct node *DeleteFirstNode(struct node *head);
void deleteLastnode(struct node *ptr, struct node *preptr);
void deleteANode(struct node *preptr, struct node *ptr, int val);

int main()
{
    // this is a pointer which will store the address of the first node of the LL
    struct node *head;

    // created 4 pointer variables which will store the addresses of a struct node datatype variable
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;

    first = (struct node *)malloc(sizeof(struct node));
    // created my first node in the heap memory and stored its address in the head pointer.
    second = (struct node *)malloc(sizeof(struct node));
    // created my second node in the heap memory and stored its address in the second pointer.
    third = (struct node *)malloc(sizeof(struct node));
    // created my third node in the heap memory and stored its address in the third pointer.
    fourth = (struct node *)malloc(sizeof(struct node));
    // created my fourth node in the heap memory and stored its address in the fourth pointer.

    head = first;
    // NOTE head isn't a node . head & first r both pointing to the same first node
    first->data = 7;
    first->next = second;

    second->data = 14;
    second->next = third;

    third->data = 21;
    third->next = fourth;

    fourth->data = 28;
    fourth->next = NULL;

    linkedListTraversal(head); // passing the address of the first node as input

    head = insertAtBeginning(head);
    linkedListTraversal(head);

    insertAtEnd(head);
    linkedListTraversal(head);

    int x;
    printf("\nEnter the data after which you want to insert a new node:");
    scanf("%d", &x);
    insertAfterGivenNode(head, x);

    linkedListTraversal(head);

    int y;
    printf("Enter the data before which you want to insert a new node:\n");
    scanf("%d", &y);
    insertBeforeGivenNode(head, head, y);

    linkedListTraversal(head);

    head = DeleteFirstNode(head);
    printf("\nAfter deletion of the first element:");
    linkedListTraversal(head);

    printf("\nAfter deletion of the last element:");
    deleteLastnode(head, head);
    linkedListTraversal(head);

    printf("\nEnter the element whose next node needs to be deleted");
    int val;
    scanf("%d", &val);
    deleteANode(head, head, val);
    linkedListTraversal(head);

    return 0;
}

// the function is going to take the address of a struct node datatype variable as input.
void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// ptr will get the address of the first node , I'll pass head to it.
struct node *insertAtBeginning(struct node *ptr)
{
    int n;
    printf("\nEnter the value to be stored in the first node:");
    scanf("%d", &n);

    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));

    NewNode->data = n;
    NewNode->next = ptr;

    // currently both NewNode and head are pointing to the first node
    return NewNode;
}

void insertAtEnd(struct node *ptr)
{

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    // after the complete execution of the while loop ptr contains the address of the node pointing to null
    int n;
    printf("\nEnter the value to be stored in the last node:");
    scanf("%d", &n);

    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));
    // NewNode contains the address of the new node just created in the heap memory

    NewNode->data = n;
    NewNode->next = NULL;

    ptr->next = NewNode;
}

void insertAfterGivenNode(struct node *ptr, int val)
{
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    // after the execution of this while loop ptr will contain the address of the node whose data=val. Thus we will get the address of the node after which we want to insert our node

    int n;
    printf("\nEnter the value to be stored in the new node :");
    scanf("%d", &n);

    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));

    NewNode->data = n;
    NewNode->next = ptr->next;

    ptr->next = NewNode;
}

void insertBeforeGivenNode(struct node *preptr, struct node *ptr, int val)
{
    // initially both preptr and ptr contain the address of the first node
    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    // after the execution of the while loop ptr contains the address of the node before which we want to insert a new node . preptr contains the address of the node which is present right before the one pointed by ptr

    int n;
    printf("\nEnter the value to be inserted in the node");
    scanf("%d", &n);

    struct node *NewNode;
    NewNode = (struct node *)malloc(sizeof(struct node));

    NewNode->data = n;
    NewNode->next = ptr;

    preptr->next = NewNode;
}

// in head I'll pass the address of the first node which is supposed to be deleted
struct node *DeleteFirstNode(struct node *head)
{
    if (head == NULL)
    {
        printf("LinkedList is empty");
    }
    else
    {
        struct node *ptr;  // ptr is a pointer which stores the address of a struct node datatype variable
        ptr = head;        // ptr is pointing to the current node
        head = head->next; // head is pointing to the second node
        free(ptr);
    }
    return head;
}

void deleteLastnode(struct node *ptr, struct node *preptr)
{
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    // after the execution of this while loop ptr points to the last node and preptr points to the second last node

    preptr->next = NULL;
    free(ptr);
}

void deleteANode(struct node *preptr, struct node *ptr, int val)
{
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    // preptr contains the address of the node jiske baad waala node needs to be deleted
    // ptr contains the address of the node which needs to be deleted

    struct node *temp;
    temp = ptr;
    preptr->next = ptr->next;

    free(temp);
}
// in malloc before the address got initialized in the pointers for the nodes , the empty space got filled with variables (empty).

// pointers are passed using call by value so if you pass the address of a node stored in a pointer to a function the address in the pointer wont change even if it is changing in the function definition.