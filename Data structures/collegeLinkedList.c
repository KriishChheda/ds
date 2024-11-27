#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // box which is going to store the address of a struct node variable
};

void DisplayLinkedList(struct node *ptr);
struct node *insertBeginning(struct node *head);

int main()
{
    struct node *head; // contains the address of the first node
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    // head = (struct Node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));  // head contains the address of the first node
    second = (struct node *)malloc(sizeof(struct node)); // second contains the address of the second node
    third = (struct node *)malloc(sizeof(struct node));  // third contains the address of the third node
    fourth = (struct node *)malloc(sizeof(struct node)); // fourth contains the address of the fourth node
    fifth = (struct node *)malloc(sizeof(struct node));  // fifth contains the address of the fifth node

    // Head pointing to the first node
    head = first;

    // using the address od the node i can access the members of the node
    first->data = 7;
    first->next = second; // only head knows the address of the second node

    second->data = 14;
    second->next = third; // only second has the address of the third node

    third->data = 21;
    third->next = fourth;

    fourth->data = 28;
    fourth->next = fifth;

    fifth->data = 35;
    fifth->next = NULL;

    DisplayLinkedList(head);

    head = insertBeginning(head);

    DisplayLinkedList(head);

    return 0;
}
// ptr has the address of the first node thats created (head)
void DisplayLinkedList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertBeginning(struct node *head)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));

    int n;
    printf("Enter the element to be inputted in the node \n");
    scanf("%d", &n);

    new->data = n;
    new->next = head;

    head = new;
    return head;
}