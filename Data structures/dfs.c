#include <stdio.h>

void dfs(int adj[10][10], int visited[], int start, int n);
void main()
{
    int n, i, j;
    printf("Enter the total no of nodes in the graph\n");
    scanf("%d", &n);

    // created an array where every memory location corresponds to one node
    int visited[n];

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int adj[10][10];
    printf("Enter the elements of the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    dfs(adj, visited, 0, n);
}

// start is the first node(root node) from where we are starting our traversals
void dfs(int adj[10][10], int visited[], int start, int n)
{
    int stack[10];
    int top = -1, i;
    stack[++top] = start;
    visited[start] = 1;
    printf("%d ", start);

    while (top != -1)
    {
        start = stack[top];
        for (i = 0; i < n; i++)
        {
            if ((adj[start][i] == 1) && (visited[i] == 0))
            {
                stack[++top] = i;
                visited[i] = 1;
                printf("%d ", i);
                break;
            }
        }
        if (i == n)
        {
            top--;
        }
    }
}