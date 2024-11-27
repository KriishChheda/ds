#include <stdio.h>
#include <stdlib.h>

int main()
{
    // USING MALLOC()
    int *ptr; // created a variable which stored the address of some integer
    ptr = (int *)malloc(10 * sizeof(int));
    // ptr contains the address of the 1st byte of the reserved 40 bytes of heap memeory
    for (int i = 0; i < 3; i++)
    {
        printf("Enter a no");
        scanf("%d", &ptr[i]); // ptr[i] means * ptr+i
    }

    for (int i = 0; i < 3; i++)
    {
        printf("The value at %d of this array is %d\n", i, ptr[i]);
    }

    return 0;
}