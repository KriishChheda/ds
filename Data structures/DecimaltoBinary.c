//  18/2 -->9  rem =0
//  9/2  -->4  rem =1
//  4/2  -->2  rem =0
//  2/2  -->1  rem =0

#include <stdio.h>
int arr[100]; // created an array containing 100 boxes
int top = -1; // created a var containing the address of topmost element of the array
void push(int r);
void display();

void main()
{
    int n;
    printf("\nenter a decimal number to be converted to binary\n");
    scanf("%d", &n);
    while (n > 0)
    {
        int r = n % 2;
        push(r);
        n = n / 2;
    } // once the while loop is over i will be done filling my stack with binary no's
    display(); // this will print my entire array
}
void push(int r)
{
    // r contains the binary no which needs to be pushed in the stack
    top = top + 1;
    arr[top] = r;
}
void display()
{
    printf("[");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("]");
}