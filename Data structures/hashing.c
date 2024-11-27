#include <stdio.h>

void delete();
void display();
void insert();
void search();

int ht[10], i, found;

void main()
{
    for (i = 0; i < 10; i++)
    {
        ht[i] = -1; // initialize every index of our hash table with -1
    }

    int choice;
    do
    {
        printf("\n-----Hash Table-----\n");
        printf("\n1] Insert\n2] Delete\n3] Display\n4] Search\n5] Exit\n");
        printf("Enter your choice: ");
        printf("\n--------------------\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        }
    } while (choice != 5);
}

// Insert function is responsible for adding a new data item to the hash table
void insert()
{
    int val, index;
    printf("Enter the data item to be inserted into the hash table: ");
    scanf("%d", &val); // this is our key

    index = val % 10; // calculated the index using the hash function

    if (ht[index] == -1)
    {
        ht[index] = val;
    }
    else
    {
        // you wanted to insert at a location which was already filled and was not the last location of the ht
        if (index < 9)
        {
            for (int i = index + 1; i < 10; i++)
            {
                if (ht[i] == -1)
                {
                    ht[i] = val;
                    break;
                }
            }
        }
        // else runs when its the insertion on the last index and that element is already filled
        else
        {
            for (int i = 0; i < index; i++)
            {
                if (ht[i] == -1)
                {
                    ht[i] = val;
                    break;
                }
            }
        }
    }
}

// Display all elements of the hash table
void display()
{
    printf("\nThe elements of the hash table are:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Index %d: %d\n", i, ht[i]);
    }
}

// Search for a key in the hash table
void search()
{
    int val, index, flag = 0;
    printf("Enter the key you want to search for: ");
    scanf("%d", &val);

    index = val % 10; // calculate the probable index using the hash function
    found = 0;

    if (ht[index] == val)
    {
        found = 1;
        printf("The key %d is at index %d.\n", val, index);
        return;
    }

    // this for loop wont run for last index i.e index = 9
    for (int i = index + 1; i < 10; i++)
    {
        if (ht[i] == val)
        {
            found = 1;
            printf("The key %d is at index %d.\n", val, i);
            return;
        }
    }

    for (int i = 0; i < index; i++)
    {
        if (ht[i] == val)
        {
            found = 1;
            printf("The key %d is at index %d.\n", val, i);
            return;
        }
    }

    if (!found)
    {
        printf("Key %d not found.\n", val);
    }
}

// Delete a key from the hash table
void delete()
{
    int val, index;
    printf("Enter the key you want to delete: ");
    scanf("%d", &val);

    search(); // if on execution of the search function , found =1 then it will be reflected here as well since its a global variable

    if (found)
    {
        index = val % 10;

        if (ht[index] == val)
        {
            ht[index] = -1;
            printf("The element %d deleted from index %d.\n", val, index);
        }
        else
        {
            for (int i = index + 1; i < 10; i++)
            {
                if (ht[i] == val)
                {
                    ht[i] = -1;
                    printf("The element %d deleted from index %d.\n", val, i);
                    return;
                }
            }

            for (int i = 0; i < index; i++)
            {
                if (ht[i] == val)
                {
                    ht[i] = -1;
                    printf("The element %d deleted from index %d.\n", val, i);
                    return;
                }
            }
        }
    }
    else
    {
        printf("Key not found, deletion unsuccessful.\n");
    }
}
