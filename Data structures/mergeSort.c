#include <stdio.h>
void merge_sort(int arr[], int beg, int end);
void merge(int arr[], int beg, int mid, int end);
void main()
{
    int n, i;
    printf("Enter the total no of elements to be inserted in the array\n");
    scanf("%d", &n);

    int arr[n]; // created an array of exactly the required size

    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The elements of the sorted array are :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    printf("The elements of the sorted array are :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// arr will contain the array to be sorted
// beg will contain the first index of the unsorted array
// end will contain the last index of the unsorted array
void merge_sort(int arr[], int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

// arr will contain the array which contains the two subarrays to merge
// beg will contain the index of the first element of the first subarray
// mid will contain the index of the last element of the first subarray
// end will contain the index of the last element of the last subarray
// i is used for indexing the first subarray
// j is used for indexing the second subarray
// temp is the array where the merged array will be stored temporarily
// size is the total elements present in the merged array
// index is used for indexing the merged array
void merge(int arr[], int beg, int mid, int end)
{
    int i, j, size, k, index;
    i = beg;
    index = beg;
    j = mid + 1;
    size = end + 1;
    int temp[size];

    while ((i <= mid) && (j <= end))
    {
        if (arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    // if the while loop terminates because first subarray is completely traversed
    if (i > mid)
    {
        // copy the remianing elements of the second subarray into our merged array
        while (j <= end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    // if the while loop terminates because second subarray is completely traversed
    else
    {
        // copy the remianing elements of the first subarray into our merged array
        temp[index] = arr[i];
        i++;
        index++;
    }
    for (k = beg; k < index; k++)
    {
        arr[k] = temp[k];
    }
}
