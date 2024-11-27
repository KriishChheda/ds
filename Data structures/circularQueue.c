#include <stdio.h>

int cq[10];
int rear = -1, front = -1;
void insert();
void display();
void Delete();

void main()
{
    int choice;
    do
    {
        printf("\n----Circular Queue---\n");
        printf("\n1]insert\n2]display\n3]delete\n4]exit\n");
        printf("\nEnter your choice\n");
        printf("-------------------------\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            Delete();
            break;
        }
    } while (choice != 4);
}

void insert()
{
    if ((rear + 1) % 10 == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        int n;
        // during the first insertion this will work
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % 10;
        }
        printf("\nEnter the element to be added\n");
        scanf("%d", &n);
        cq[rear] = n;
    }
}
void Delete()
{
    int n = cq[front];
    if (rear == -1 && front == -1)
    {
        printf("\nqueue is empty\n");
    }
    else
    {
        if (rear == front)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            front = (front + 1) % 10;
        }
    }
    printf("\nThe element to be deleted is %d", n);
}
void display()
{
    if (rear == -1 && front == -1)
    {
        printf("\nqueue is empty\n");
    }
    else
    {
        printf("the elements of the queue are \n");
        for (int i = front; i != rear; i = (i + 1) % 10)
        {
            printf("\n%d", cq[i]);
        }
        printf("\n%d", cq[rear]);
    }
}