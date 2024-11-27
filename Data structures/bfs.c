#include <stdio.h>

void bfs(int adj[10][10], int visited[], int start, int n);
void main()
{
    int n, i, j;
    printf("\nEnter the total no of nodes present in the graph\n");
    scanf("%d", &n);

    // corresponding to every node there should be one memory location in the visited array.
    int visited[n];
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    // initialised all memory locations of the visited array to 0 , since no node is visited yet

    int adj[10][10];
    printf("Enter the adjacency matrix of the graph\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    bfs(adj, visited, 0, n); // this will print all the nodes systematically
}

// adj contains our adjaceny matrix
// start contains the root node we want to start traversing with
// n contains the total no of nodes
void bfs(int adj[10][10], int visited[], int start, int n)
{
    int queue[n], i;
    int rear = -1, front = -1;
    rear++;
    queue[rear] = start;
    visited[start] = 1;

    while (rear != front)
    {
        int current = queue[++front];
        printf("%d ", current);

        for (i = 0; i < n; i++)
        {
            if ((adj[current][i] == 1) && (visited[i] == 0))
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}