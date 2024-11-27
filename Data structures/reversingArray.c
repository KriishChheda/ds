#include <stdio.h>
int top = -1;
int stack[100];
void push(int x);
int pop();
// push , pop are the three functions which will be used on the array
void main()
{

    int n, i;
    printf("\nEnter the total no of terms to be stored in the array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        push(arr[i]);
    }
    // the 1st ele of the array is the 1 st ele of the stack .
    printf("\nThe elements of the array are :\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    // technically we have a copy of our array in our stack , so even if our og array changes its ok
    for (i = 0; i < n; i++)
    {
        arr[i] = pop();
        /* the elements will start getting popped from the top so the topmost element of the stack which is the
          last element of the stack that is the last element of the og array will be stored in val first */
    }
    printf("\nThe elements of the reversed array are:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void push(int x)

{
    top = top + 1;
    stack[top] = x;
}

int pop()
{
    int val = stack[top];
    top = top - 1;
    return val;
}