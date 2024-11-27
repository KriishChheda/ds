#include <stdio.h>

void inputRestricted();
void outputRestricted();
void insert_left();
void insert_right();
void delete_left();
void delete_right();
void display();

int left = -1, right = -1;
int DEqueue[10];

void main()
{
    int choice;
    printf("------MAIN MENU------");
    printf("\n1]input restricted queue");
    printf("\n2]Output restricted queue\n");
    printf("Enter your choice\n");
    printf("---------------------");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        inputRestricted();
        break;
    case 2:
        outputRestricted();
        break;
    }
}

void inputRestricted()
{
    int choice;
    do
    {
        printf("---INPUT RESTRICTED---");
        printf("\n1]Insert(right)\n2]Delete(left)\n3]Delete(right)\n4]display\n5]Exit\n");
        printf("enter your choice\n");
        printf("\n----------------------\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insert_right();
            break;

        case 2:
            delete_left();
            break;

        case 3:
            delete_right();
            break;

        case 4:
            display();
            break;
        }
    } while (choice != 5);
}

void outputRestricted()
{
    int choice;
    do
    {
        printf("---OUTPUT RESTRICTED---");
        printf("\n1]Insert(right)\n2]Insert(left)\n3]Delete(left)\n4]display\n5]Exit\n");
        printf("enter your choice\n");
        printf("----------------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_right();
            break;

        case 2:
            insert_left();
            break;

        case 3:
            delete_left();
            break;

        case 4:
            display();
            break;
        }
    } while (choice != 5);
}

void insert_right()
{
    int n;
    printf("Enter a number");
    scanf("%d", &n);
    if ((left == 0 && right == 9) || (left == right + 1))
    {
        printf("queue is full");
    }
    else if (left == -1 && right == -1)
    { // after first insertion left and right will both become 0
        left = 0;
        right = 0;
    }
    else
    {
        if (right == 9) // this will be true when left!=0 and right is at 9
        {
            right = 0;
        }
        else
        {
            right = right + 1;
        }
    }
    DEqueue[right] = n;
}

void insert_left()
{
    int n;
    printf("Enter a number");
    scanf("%d", &n);
    if ((left == 0 && right == 9) || (left == right + 1))
    {
        printf("Queue is full");
    }
    else if (right == -1)
    { // for first insertion irrespective of whether its left or right insertion will happen at index 0
        right = 0;
        left = 0;
    }
    else
    {
        if (left == 0)
        {
            left = 9;
        }
        else
        {
            left = left - 1;
        }
    }
    DEqueue[left] = n;
}

void delete_left()
{
    int n;
    n = DEqueue[left];
    if (left == -1)
    {
        printf("\nQueue is empty\n");
    }
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if (left == 9)
        {
            left = 0;
        }
        else
        {
            left = left + 1;
        }
    }
    printf("\nThe element which is deleted is %d\n", n);
}

void delete_right()
{
    int n;
    n = DEqueue[right];
    if (right == -1)
    {
        printf("\nQueue is empty\n");
    }
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if (right == 0)
        {
            right = 9;
        }
        else
        {
            right = right - 1;
        }
    }
    printf("\nThe element which is deleted is %d\n", n);
}
void display()
{
    printf("\nThe elements of the De-queue are:\n");
    int front = left, rear = right;
    if (front <= rear)
    {
        while (front <= rear)
        {
            printf("%d\n", DEqueue[front]);
            front++;
        }
    }
    else
    {
        while (front <= 9)
        {
            printf("%d\n", DEqueue[front]);
            front++;
        }
        front = 0;
        while (front <= rear)
        {
            printf("%d\n", DEqueue[front]);
            front++;
        }
    }
    printf("\n");
}

// in case of insertion from right the display function prints the numbers in ascending order
// in case of insertion from left the display function prints the numbers in descending order