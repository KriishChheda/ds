#include <stdio.h>
#define max 10;        // we created a variable called max which has 10 fixed
int arr[10], top = -1; // array is a static data structure , so an array of size 10 will be made during compile time
void push();
void peek();
void pop();
void display();
void main()
{
    int choice;
    do
    {
        printf("\n------Stack------\n");
        printf("\n1]push\n2]pop\n3]peek\n4]display\n5]Exit\n");
        printf("Enter your choice \n");
        printf("\n-----------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        }
    } while (choice != 5);
}

void push()
{
    if (top == 9)
    {
        printf("Stack overflow"); // overflow condition
    }
    else
    {
        int n;
        printf("Enter the element to be pushed in the stack: ");
        scanf("%d", &n);
        top = top + 1; // top is a variable which has the address of the latest element to be inserted or removed
        arr[top] = n;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        int n = arr[top]; // n will contain the element to be popped
        top = top - 1;
        printf("\nThe element which is popped is %d", n);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nthe top most element is %d", arr[top]);
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("The elements of the array are \n");
        for (int i = 0; i <= top; i++)
        {
            printf("\n%d", arr[i]);
        }
    }
}