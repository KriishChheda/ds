#include <stdio.h>

int smallest(int arr[], int k, int n);
void selection_sort(int arr[], int n);
void main()
{
    int n, i;
    printf("Enter the total no of terms in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the unsorted array are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    selection_sort(arr, n); // this function will sort the elements of the array arr in itself

    printf("\nThe elements of the sorted array are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// this function is responsible for swapping the first element of the unsorted list with the smallest element of the unosorted list
void selection_sort(int arr[], int n)
{
    int k, pos, temp;
    for (k = 0; k < n; k++)
    {
        pos = smallest(arr, k, n);
        temp = arr[pos];
        arr[pos] = arr[k];
        arr[k] = temp;
    }
}

// this function is responsible for returning the index of the smallest element of the unsorted list
int smallest(int arr[], int k, int n)
{
    int min = arr[k];
    int pos = k, i;

    for (i = k + 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            pos = i;
        }
    }
    return pos;
}

// k is used to store the index of the first element of the unsorted list
// pos is used to store the index of the smallest element of the unsorted list
// we have to swap the first element of the unsorted list with the smallest element of the unsorted list
