#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int max, min; // max and min are both global functions.
void maxmin(int arr[], int low, int high);
int main()
{
    clock_t start, end, ans;
    int n = 100000;
    int arr[n];
    int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
    start = clock();
    maxmin(arr, 0, n - 1);
    end = clock();
    ans = end - start;
    printf("\nThe maximum element of the array is %d ", max);
    printf("\nThe minimum element of the array is %d ", min);

    printf("\nThe time taken to compute the max and min element out of %d elements is %ld", n, ans);
}
void maxmin(int arr[], int low, int high)
{
    int max1, min1, mid;
    if (low == high)
    {
        min = max = arr[high];
    }
    else if (low == high - 1)
    {
        if (arr[low] < arr[high])
        {
            min = arr[low];
            max = arr[high];
        }
        else
        {
            min = arr[high];
            max = arr[low];
        }
    }
    else
    {
        mid = (low + high) / 2;
        maxmin(arr, low, mid); 
        max1 = max;
        min1 = min;
        maxmin(arr, mid + 1, high); 
        //combination of the 2 subproblems take place now
        if (max1 > max)
        {
            max = max1;
        }
        if (min1 < min)
        {
            min = min1;
        }
    }
}