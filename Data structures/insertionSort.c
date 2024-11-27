#include <stdio.h>

void insertion_sort(int arr[], int n);
void main()
{
    int n, i;
    printf("Enter the total no of terms to be stored in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the unsorted array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the unsorted array are : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    insertion_sort(arr, n); // changes will be made in the original array itself

    printf("\nThe elements of the sorted array are : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertion_sort(int arr[], int n)
{
    // i is used for traversing the unsorted list
    // j is used for traversing the sorted list
    // temp is used to store the first element of the unsorted list
    // we traverse the unosrted list from L->R and the sorted list from R->L
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while ((temp < arr[j]) && (j >= 0))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}