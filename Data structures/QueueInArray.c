#include <stdio.h>

void insert();
void Delete();
void display();
int stack[10];
int rear = -1, front = 0;
// rear stores the address of the latest element
// front stores the address of the first element of the queue

void main()
{
    int choice;
    do
    {
        printf("\n------QUEUE------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice");
        printf("\n-----------------\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            Delete();
            break;

        case 3:
            display();
            break;
        }

    } while (choice != 4);
}

void insert()
{
    if (rear == 9)
    {
        printf("\nQueue is full\n");
    }

    else
    {
        int n;
        printf("\nEnter a number:");
        scanf("%d", &n);
        rear = rear + 1;
        stack[rear] = n;
    }
}

void Delete()
{

    if (front > rear)
    {
        front = 0;
        rear = -1;
        printf("\nQueue is empty\n");
    }
    else
    {
        int n;
        n = stack[front];
        printf("\nThe deleted element is %d", n);
        front = front + 1;
    }
}

void display()
{
    if (front > rear)
    {
        front = 0;
        rear = -1;
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nThe elements of the queue are :\n");
        for (int i = front; i <= rear; i++)
        {
            printf("\n%d", stack[i]);
        }
    }
}
