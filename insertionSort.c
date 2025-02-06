#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int arr[], int n);
void reverse(int arr[], int n);
int main()
{
    int i, n = 100000;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
    clock_t start, end;
    double ans;
    start = clock(); // total no of clock ticks the processor took to execute so far
    insertionSort(arr, n);
    end = clock(); // total no of clock ticks the processor took to execute so far
    ans = (double)end - (double)start;
    printf("CPU time taken for insertion sort of %d random numbers : %f\n", n, ans);
    start = clock(); // total no of clock ticks the processor took to execute so far
    insertionSort(arr, n);
    end = clock(); // total no of clock ticks the processor took to execute so far
    ans = (double)end - (double)start;
    printf("CPU time taken for insertion sort of %d sorted ascending numbers : %f\n", n, ans);
    reverse(arr, n);
    start = clock(); // total no of clock ticks the processor took to execute so far
    insertionSort(arr, n);
    end = clock(); // total no of clock ticks the processor took to execute so far
    ans = (double)end - (double)start;
    printf("CPU time taken for insertion sort of %d sorted descending numbers : %f\n", n, ans);
}
// Element at index 0 is considered to be a part of the sorted array
// Element at index 1 is the first element of the unsorted array
void insertionSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        temp = arr[i];
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void reverse(int arr[], int n)
{
    int i, j, temp;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}