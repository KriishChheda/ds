#include <stdio.h>
int topA = -1, topB = 10, arr[10]; // created an array of size 10
// topA is a variable which will store the address of the topmost element of stack A
// topB is a variable which will store the address of the topmost element of stack B

// two stacks are working on the same array
// the end for insertion and deletion of elements from stack 1 is from the right
// the end for insertion and deletion of elements from stack 2 is from the left
void push1();
void pop1();
void push2();
void pop2();
void display1();
void display2();

void main()
{
    int choice;
    do
    {
        printf("------Double Stack------");
        printf("\n1]push1\n2]pop1\n3]push2\n4]pop2\n5]display1\n6]display2\n7]exit\n");
        printf("Enter your choice");
        printf("\n------------------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push1();
            break;

        case 2:
            pop1();
            break;

        case 3:
            push2();
            break;

        case 4:
            pop2();
            break;

        case 5:
            display1();
            break;

        case 6:
            display2();
            break;
        }
    } while (choice != 7);
}

void push1()
{
    if (topA + 1 == topB)
    {
        printf("\nStack 1 is full\n");
    }
    else
    {
        int n;
        printf("Enter a number:");
        scanf("%d", &n);
        topA = topA + 1;
        arr[topA] = n;
    }
}

void pop1()
{
    if (topA == -1)
    {
        printf("\nStack 1 is empty\n");
    }
    else
    {
        int n = arr[topA];
        topA = topA - 1;
        printf("\nelement that is popped is %d\n", n);
    }
}

void display1()
{
    if (topA == -1)
    {
        printf("\nStack 1 is empty\n");
    }
    // theres nothing to print if the stacks empty
    else
    {
        printf("\nthe elements of stack 1 are\n");
        for (int i = topA; i >= 0; i--)
        {
            printf("\n%d", arr[i]);
        }
    }
}

void push2()
{
    if (topB - 1 == topA)
    {
        printf("\nStack 2 is full\n");
    }
    else
    {
        topB = topB - 1;
        int n;
        printf("\nEnter a number:\n");
        scanf("%d", &n);
        arr[topB] = n;
    }
}
void pop2()
{
    if (topB == 10)
    {
        printf("\nStack 2 is empty\n");
    }
    else
    {
        int n = arr[topB];
        topB = topB + 1;
        printf("\nelement that is popped is %d\n", n);
    }
}
void display2()
{
    if (topB == 10)
    {
        printf("Stack 2 is empty");
    }
    else
    {
        printf("\nElements of array 2 are:\n");
        for (int i = topB; i <= 9; i++)
        {
            printf("\n%d", arr[i]);
        }
    }
}