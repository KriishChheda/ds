#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
int main()
{
    clock_t start, end, ans;
    int n = 50000;
    int arr[n]; // created an array of size 5
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 50000;
    }
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    ans = end - start;
    printf("Time taken to merge sort %d elements is : %ld", n, ans);
    return 0;
}

// this function is responsble for sorting the array i pass
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, size = high + 1, k = low;
    int temp[size];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    if (i > mid)
    {
        while (j <= high)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
    }
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}
