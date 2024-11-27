#include <stdio.h>
int partition(int arr[], int lb, int ub);
void quick_sort(int arr[], int lb, int ub);
void main()
{
    int n, i;
    printf("Enter the total no of terms to be stored in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter the elements of the array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    quick_sort(arr, 0, n - 1); // on complete execution of this function i expect my array to be sorted

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// this function is responsible for returning the correct index of the pivot element
// arr takes the input of an unsorted array
// lb contains the index of the first element of the unsorted list
// ub contains the index of the last element of the unsorted list
int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb]; // we choose pivot as the first element of the unsorted list
    int start = lb;
    int end = ub;
    while (start < end)
    {
        // till the time we dont find an element greater than pivot we increase start
        while (arr[start] <= pivot)
        {
            start++;
        }

        // till the time we dont find an element smaller than pivot we decrease end
        while (arr[end] > pivot)
        {
            end--;
        }

        // after the execution of both the while loops start contains the index of the array element which is greater than pivot and end contains the index of the array element which is smaller than pivot.

        if (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    // once the outer (parent) while loop is done executing it means start has crossed end.
    // now end contains the index where the pivot element has to be stored .
    // we swap the end and the pivot element

    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end; // returned the correct index of the pivot element
}

void quick_sort(int arr[], int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = partition(arr, lb, ub); // loc will contain the index of the pivot element when lowerbound is lb and upperbound is ub

        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}