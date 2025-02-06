// We are trying to analyse the time complexity of the sorting function here
#include <stdio.h>
#include <time.h>   // for using functions like time() and clock()
#include <stdlib.h> // for using rand() function

void selectionSort(int arr[], int n);
void reverse(int arr[], int n);
int main()
{
    int i, n = 100000;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        arr[i] = (rand() % 100000) + 1;
    }
    clock_t start, end;
    double ans;
    start = clock();
        selectionSort(arr, n);
    end = clock();
    ans = (double)end - (double)start;
    printf("CPU time taken for selection sort of %d random numbers : %f\n", n, ans);
    start = clock();
        selectionSort(arr, n); // we passed a sorted array here
    end = clock();
    ans = (double)end - (double)start;
    printf("CPU time taken for selection sort of %d sorted ascending numbers : %f\n", n, ans);
        reverse(arr, n);// this function reversed the array in itself
    start = clock();
        selectionSort(arr, n);// passed a sorted descending array here
    end = clock();
    ans = (double)end - (double)start;
    printf("CPU time taken for selection sort of %d sorted descending numbers : %f\n", n, ans);
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

void selectionSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[minIdx] > arr[j])
            {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}