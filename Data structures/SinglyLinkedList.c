#include <stdio.h>
#include <stdlib.h> // for malloc calloc realloc and free
#include <string.h>

// creating a new data type called struct node
// struct node* next is a pointer which will store the address of a struct node datatype variable
struct node
{
    int data;
    struct node *next;
};

// whenever i create a variable of the struct node datatype , it will contain a var to store an integer and it will contain a pointer to store the address of a struct node datatype var

struct node *createList();
struct node *createNode();
struct node *insertNode(struct node *ptr);
struct node *insert_head(struct node *ptr);
struct node *insert_last(struct node *ptr);
struct node *insert_after(struct node *ptr);
struct node *del(struct node *ptr);
struct node *delFirst(struct node *ptr);
struct node *delLast(struct node *temp);
struct node *delAfter(struct node *temp);
void display(struct node *ptr);
struct node *reverse(struct node *ptr);

void main()
{
    struct node *Head; // Head is a pointer which will store the address of the struct node datatype variable
    Head = NULL;
    int choice;
    do
    {
        printf("Enter your choice:\n");
        printf("\n1]Create List\n");
        printf("\n2]Display\n");
        printf("\n3]Insert\n");
        printf("\n4]Delete\n");
        printf("\n5]Reverse\n");
        printf("\n6]Exit\n");
        printf("\n---------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Head = createList(); // the function call will return the address of the first node
            break;

        case 2:
            display(Head);
            break;

        case 3:
            Head = insertNode(Head);
            break;

        case 4:
            Head = del(Head);
            break;

        case 5:
            Head = reverse(Head);
            break;
        }
    } while (choice != 6);
}

struct node *createList()
{
    // the linked list hasnt been made yet
    // created 3 pointers to store the address of a struct node datatype variable
    struct node *New, *Head, *temp;
    int val;
    char ans;

    Head = NULL;
    temp = NULL;
    ans = 'y';

    while ((ans == 'y') || (ans == 'Y'))
    {
        New = createNode();

        if (New == NULL)
        {
            printf("\nMemory is not allocated.");
            return NULL; // whenever we write return, function se hi pointer nikal jaata he
        }

        printf("\nEnter new element:");
        scanf("%d", &val);
        New->data = val;

        // at this point our node is completely ready to be inserted in the list

        // if head = null then linked list is empty and the node just created will be the first node
        if (Head == NULL)
        {
            Head = New;
            temp = Head;
        }
        // after first insertion head and temp are both going to point to the first node of the linked list
        // if its not the first insertion then else is going to run
        else
        {
            temp->next = New;
            temp = New;
        }
        printf("Do you want to add more elements ?");
        scanf("%c", &ans);
    }

    return Head;
    // createList function mein at least one node will get created for sure .Head will get initialized with the address of the first node
}

struct node *createNode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    // temp contains the address of the newly created node

    temp->next = NULL; // the newly created node is not pointing to anything
    return temp;
}

// we'll be passing the address contained in head to ptr
// Therefore ptr contains the address of the first node
void display(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("The list is empty.\n");
    }
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// in insert we'll pass the address of the first node
struct node *insertNode(struct node *ptr)
{

    struct node *temp; // created a pointer named temp which is going to store the address of a struct node datatyep variable
    printf("Select the position for insertion of the node\n");
    printf("\n1]Insert at start");
    printf("\n2]Insert at end");
    printf("\n3]Insert at a given location\n");
    printf("-----------------------------------------------\n");

    int choice;
    scanf("%d", &choice);

    // all these cases will take the input of the address of the first node and return the new address of the first node
    switch (choice)
    {
    case 1:
        temp = insert_head(ptr);
        break;
    case 2:
        temp = insert_last(ptr);
        break;

    case 3:
        temp = insert_after(ptr);
        break;
    }
    return temp;
}

// we'll pass the address of the first node that is the address contained in head to ptr
struct node *insert_head(struct node *ptr)
{
    // ptr thus contains the address of the first node
    struct node *New;
    New = createNode(); // New contains the address of the newly created node present in the heap memory

    int val;
    printf("Enter the data to be stored in the node\n");
    scanf("%d", &val);

    New->data = val;
    //  at this point our node is ready to be inserted

    if (ptr == NULL)
    {
        ptr = New;
    }
    // if ptr is NULL it means our linked list is empty , the node we've created is going to be the first node
    else
    {
        New->next = ptr;
        ptr = New;
    }
    return ptr; // returning the new address of head
}

// ptr will contain the address contained in head i.e the address of the first node
struct node *insert_last(struct node *ptr)
{

    struct node *temp = ptr;
    // temp and ptr both contain the address of the first node

    // first create a node make it ready for insertion
    struct node *New;
    New = createNode();

    int val;
    printf("Enter the data to be stored in the node\n");
    scanf("%d", &val);

    New->data = val;

    if (ptr == NULL)
    {
        // its going to be the first insertion
        ptr = New;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // after the execution of this while loop ptr will contain the address of the last node
        temp->next = New;
    }

    return ptr;
}

// ptr contains the address present in the head
struct node *insert_after(struct node *ptr)
{
    struct node *temp = ptr;

    struct node *New;
    New = createNode();
    // createNode will create a new node and initialize its next with NULL and return its address to New

    int val;
    printf("Enter the data to be stored in the node\n");
    scanf("%d", &val);

    New->data = val;

    if (ptr == NULL)
    {
        ptr = New;
    }

    // else will execute when the linked list is not empty
    else
    {
        int key;
        printf("Enter the key after which the node needs to be inserted\n");
        scanf("%d", &key);

        while (temp->data != key)
        {
            temp = temp->next;
        }
        // after the execution of this while loop temp will contain the address of the node jiske baad we've to insert our new node

        New->next = temp->next;
        temp->next = New;
    }
    return ptr;
}

// del function is going to return an address of a struct node* datatype variable.
struct node *del(struct node *ptr)
{
    struct node *temp;
    int choice;
    printf("Enter the position from where you want to delete\n");
    printf("\n1]Delete from start");
    printf("\n2]Delete from end");
    printf("\n3]Delete after a given node");

    scanf("%d", &choice);
    switch (choice)
    {
        // in all the cases i am passing the address present in the head and the functions r returning the new address of the head
    case 1:
        temp = delFirst(ptr);
        break;
        // on deleting the first element the address stored in head is going to change
    case 2:
        temp = delLast(ptr);
        break;

    case 3:
        temp = delAfter(ptr);
        break;
    }

    return temp;
}

// ptr will contain the address of the first node which is to be deleted
struct node *delFirst(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("Linked List is empty\n");
        return NULL;
    }
    struct node *temp;
    temp = ptr;
    // temp and ptr are two pointers which are pointing to the same first node which is to be deleted
    ptr = ptr->next;
    // ptr contains the address of the second node which is going to be the first node after deletion

    free(temp);
    return ptr;
}

// this delLast function is going to delete the last node
//  temp mein ill pass head which means temp contains the address of the first node
struct node *delLast(struct node *temp)
{
    // temp contains the address of the first node
    // i want the address of the second last node so that i can set the next of the second last node to NULL
    // i want the address of the last node so that i can free it

    if (temp == NULL)
    {
        printf("Linked List is empty");
    }
    struct node *ptr, *preptr;
    ptr = temp;
    preptr = temp;

    // preptr and ptr r two pointers which are pointing to the first node

    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    // after the execution of this while loop ptr contains the address of last node and preptr contains the address of the second last node
    preptr->next = NULL;
    free(ptr);

    return temp;
}

struct node *delAfter(struct node *temp)
{
    if (temp == NULL)
    {
        printf("Linked List is empty");
    }

    struct node *ptr, *preptr;
    ptr = temp;
    preptr = temp;
    // ptr and preptr will both have the addresses of the first node ,i.e. they r both pointing to the first node

    int key;
    printf("Enter the element whose next node is to be deleted\n");
    scanf("%d", &key);

    while (preptr->data != key)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    // preptr contains the address of the node jiske baad waala node needs to be deleted and ptr contains the address of the node which is to be deleted

    preptr->next = ptr->next;
    free(ptr);
}

struct node *reverse(struct node *ptr)
{
    struct node *prev = NULL;
    struct node *current = ptr;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // next will contain the address of the next node which only the current node has
        current->next = prev; // current node will start pointing to the prev node
        prev = current;
        current = next;
    }
    return prev;
}