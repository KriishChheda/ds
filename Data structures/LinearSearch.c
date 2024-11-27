#include <stdio.h>
#include <stdbool.h>

void main()
{
    bool flag = false;
    int n, i, index;
    printf("Enter the total no of elements to be stored in the array\n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the array element to search for in our array\n");
    scanf("%d", &x);

    for (i = 0; i < n; i++)
    {
        if (x == arr[i])
        {
            flag = true;
            index = i;
        }
    }

    if (flag == true)
    {
        printf("Searching is successful.\nThe array element is stored at index %d", index);
    }
    else
    {
        printf("Searching is unsuccesful.\nArray element not found.");
    }
}