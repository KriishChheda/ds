#include <stdio.h>

int binary_search(int arr[], int n, int x);

void main()
{
    int n, i;
    printf("Enter the total no of elements to be stored in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array in ascending order\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the array element to be searched for: ");
    scanf("%d", &x);

    int ans = binary_search(arr, n, x);
    if (ans == -1)
    {
        printf("Array element not found\n");
    }
    else
    {
        printf("Searching is succesful.\nArray element is at index %d", ans);
    }
}

// this function is responsible for finding x in the array arr whose size is n.
// make sure n is odd (for better understanding)
int binary_search(int arr[], int n, int x)
{
    int beg, end, mid;
    beg = 0;
    end = n - 1;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (x > arr[mid])
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

// at least there will be one iteration of the while loop where the array element is found and the function terminates
// if the while loop terminates and the function does not return , it means the element is not found , in this case we return -1.