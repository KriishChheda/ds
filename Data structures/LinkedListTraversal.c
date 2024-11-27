#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} v1, v2;

// created our structure that contains a var called data and a pointer that will store the address of a struct Node datatype

void linkedListTraversal(struct Node *ptr);

int main()
{
    // created 3 pointers to store the address' of three struct Node variables (3 nodes in short)
    struct Node *first;
    struct Node *second;
    struct Node *third;

    // Allocate memeory for nodes in the linked list in Heap

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second node
    first->data = 7;
    first->next = second;

    // Link second and the third node
    second->data = 11;
    second->next = third;

    // Terminate list on third node
    third->data = 66;
    third->next = NULL;

    linkedListTraversal(first);
    return 0;
}

void linkedListTraversal(struct Node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\nThe total no of nodes created are : %d", count);
}