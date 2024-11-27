#include <stdio.h>

void insert();
void Delete();
void display();
int queue[10];
int rear = -1, front = -1;
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
        return;
    }
    else if (rear == -1) // its going to be the first insertion
    {
        rear = 0;
        front = 0;
        int n;
        printf("\nEnter a number:");
        scanf("%d", &n);
        queue[rear] = n;
        return;
    }
    else
    {
        rear = rear + 1;
        int n;
        printf("\nEnter a number:");
        scanf("%d", &n);
        queue[rear] = n;
        return;
    }
}

void Delete()
{

    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else if (rear == front)
    {
        int n = queue[front];
        rear = -1;
        front = -1;
        printf("\nThe deleted element is %d", n);
    }
    else
    {
        int n = queue[front];
        front = front + 1;
        printf("\nThe deleted element is %d", n);
    }
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nThe elements of the queue are :\n");
        for (int i = front; i <= rear; i++)
        {
            printf("\n%d", queue[i]);
        }
    }
}
