#include <stdio.h>
#include <stdlib.h>

struct node
{
    int exp;
    int coef;
    struct node *next;
};
// each node represents a term of the polynomial expression

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *start4 = NULL;

// start1 will contain the address of the first node of the first polynomial expression
// start2 will contain the address of the first node of the second polynomial expression
// start3 will contain the address of the first node of the added polynomial expression
// start4 will contain the address of the first node of the subtracted po;ynomial expression
// initially none of them are created so all of them are null

// each term will contain the address of the next term of the expression

struct node *CreatePoly(struct node *start);
void display(struct node *start);
struct node *add(struct node *start1, struct node *start2, struct node *start3);
struct node *add_node(struct node *start, int c, int n);
struct node *subtract(struct node *start1, struct node *start2, struct node *start4);

void main()
{
    int choice;
    do
    {
        printf("\n--------------------------\n");
        printf("1]Enter first polynomial expression\n");
        printf("2]Display first polynomial expression\n");
        printf("3]Enter second polynomial expression\n");
        printf("4]Display second polynomial expression\n");
        printf("5]Add the polynomials\n");
        printf("6]display the result\n");
        printf("7]Subtract the polynomials\n");
        printf("8]display the result\n");
        printf("9]Exit\n");
        printf("\nEnter your choice\n");
        printf("\n--------------------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start1 = CreatePoly(start1);
            break;

        case 2:
            display(start1);
            break;

        case 3:
            start2 = CreatePoly(start2);
            break;

        case 4:
            display(start2);
            break;

        case 5:
            start3 = add(start1, start2, start3);
            break;

        case 6:
            display(start3);
            break;

        case 7:
            start4 = subtract(start1, start2, start4);
            break;

        case 8:
            display(start4);
            break;
        }
    } while (choice != 9);
}

// throughout the code n = exponent and c = coefficient
// its not compulsory to create the entire linked list at once . The polynomial expression can be completely created later on also

struct node *CreatePoly(struct node *start)
{
    int n;
    printf("Enter the exponent of the term\n");
    scanf("%d", &n);

    int c;
    printf("Enter the coefficient of the term\n");
    scanf("%d", &c);

    while (n != -1)
    {
        if (start == NULL)
        {
            struct node *NewNode;
            NewNode = (struct node *)malloc(sizeof(struct node));
            NewNode->coef = c;
            NewNode->exp = n;
            NewNode->next = NULL;
            start = NewNode;
        }
        // if runs only once when the first term of the polynomial expression / first node of the linked list will be created
        else
        {
            struct node *ptr = start; // ptr contains the address of the first node of the linked list
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            // ptr points to the last node of the linked list

            struct node *NewNode;
            NewNode = (struct node *)malloc(sizeof(struct node));
            NewNode->coef = c;
            NewNode->exp = n;
            NewNode->next = NULL;
            ptr->next = NewNode;
        }

        printf("Enter the exponent of the next term (if doesn't exist input -1)\n");
        scanf("%d", &n);

        if (n == -1)
        {
            return start; // once this line executes we will come out of the function
        }
        else
        {
            printf("Enter the coefficient of the new term\n");
            scanf("%d", &c);
        }
    }
}
// lets say i input -1 as n after a few insetions, my function terminated , later on i realised i wanted to add one more node . i can again call the function , take the input of n and c , directly the else statement is going to run , a node will get inserted and i will be asked if i want to insert a new node or not!!!!!!

// the address of the first node of the linked list will be passed on to start
void display(struct node *start)
{
    if (start == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct node *ptr = start; // both ptr and start will point to the first node of the linked list
        while (ptr != NULL)
        {
            printf("\n%d x %d", ptr->coef, ptr->exp);
            ptr = ptr->next;
        }
        printf("\n\n");
    }
}

// start1 contains the address of the first node of the first polynomial ll
// start2 contains the address of the first node of the second polynomial ll
//  start 3 will contain NULL initially

struct node *add(struct node *start1, struct node *start2, struct node *start3)
{
    struct node *ptr1 = start1;
    struct node *ptr2 = start2;

    // every term of the linked list is traversed in order one by one.

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exp == ptr2->exp)
        {
            int sumCoef = ptr1->coef + ptr2->coef;
            start3 = add_node(start3, sumCoef, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->exp > ptr2->exp)
        {
            start3 = add_node(start3, ptr1->coef, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else
        {
            start3 = add_node(start3, ptr2->coef, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }

    // if the first linked list was completely traversed , the second list still has terms yet to be traversed
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            start3 = add_node(start3, ptr2->coef, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            start3 = add_node(start3, ptr1->coef, ptr1->exp);
            ptr1 = ptr1->next;
        }
    }
    return start3;
}

// the purpose of this particular function is to create the new list after the arithmetic operation
struct node *add_node(struct node *start, int c, int n)
{
    struct node *ptr, *NewNode;
    if (start == NULL)
    {
        NewNode = (struct node *)malloc(sizeof(struct node));
        NewNode->coef = c;
        NewNode->exp = n;
        NewNode->next = NULL;
        start = NewNode;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        // ptr will point to the last node of the series
        NewNode = (struct node *)malloc(sizeof(struct node));
        NewNode->coef = c;
        NewNode->exp = n;
        NewNode->next = NULL;
        ptr->next = NewNode;
    }
    return start;
}

struct node *subtract(struct node *start1, struct node *start2, struct node *start4)
{
    struct node *ptr1 = start1;
    struct node *ptr2 = start2;

    int subCoef, n;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exp == ptr2->exp)
        {
            int subCoef = ptr1->coef - ptr2->coef;
            start4 = add_node(start4, subCoef, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->exp > ptr2->exp)
        {
            start4 = add_node(start4, ptr1->coef, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else
        {
            start4 = add_node(start4, ptr2->coef, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            start4 = add_node(start4, ptr2->coef, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            start4 = add_node(start4, ptr1->coef, ptr1->exp);
            ptr1 = ptr1->next;
        }
    }
    return start4;
}