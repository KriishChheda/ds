#include <stdio.h>
int fiboSearch(int arr[], int n, int x);
int min(int x, int y);
void main()
{
    int n, i;
    printf("\nEnter the total no of elements to be stored in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array in a sorted manner:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int val;
    printf("Enter the element to search for: ");
    scanf("%d", &val);

    int ans = fiboSearch(arr, n, val);
    if (ans == -1)
    {
        printf("Search was unsuccesful.\nElement not found");
    }
    else
    {
        printf("Element found at %d", ans);
    }
}

int min(int x, int y)
{
    return (x < y ? x : y);
}
int fiboSearch(int arr[], int n, int x)
{
    // first we need to find the smallest fibo no equal to or greater than n
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }
    // once the while loop is done executing , fib will contain the smallest fibo no >= n
    // fib1 will contain one fibo no less than fib
    // fib2 will contain two fibo no less than fib

    int offset = -1;
    while (fib > 1)
    {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < x)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
        {
            return i;
        }
    }
    if (fib1 && arr[offset + 1] == x)
    {
        return offset + 1;
    }
    return -1;
}