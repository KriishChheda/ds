#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void dijkstra(int graph[9][9]);
int main()
{
    int graph[9][9] =
        {{0, 4, 0, 0, 0, 0, 0, 8, 0},
         {4, 0, 8, 0, 0, 0, 0, 11, 0},
         {0, 8, 0, 7, 0, 4, 0, 0, 2},
         {0, 0, 7, 0, 9, 14, 0, 0, 0},
         {0, 0, 0, 9, 0, 10, 0, 0, 0},
         {0, 0, 4, 14, 10, 0, 2, 0, 0},
         {0, 0, 0, 0, 0, 2, 0, 1, 6},
         {8, 11, 0, 0, 0, 0, 1, 0, 7},
         {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(graph);
}

void dijkstra(int graph[9][9])
{
    // for every node we want to store their parent , distance from origin and visited
    bool visited[9];
    int parent[9];
    int distance[9];

    for (int i = 0; i < 9; i++)
    {
        distance[i] = INT_MAX; // all the nodes are at infinity
        visited[i] = false;    // none of the nodes are visited yet
    }
    // we selected the root node as 0 . The root node has no parent and the distance of the root node is 0
    parent[0] = -1;
    distance[0] = 0;
    // initialization ends here
    for (int count = 0; count < 8; count++)
    {
        int min = INT_MAX, minIndex;
        for (int i = 0; i < 9; i++)
        {
            if (visited[i] == false && distance[i] < min)
            {
                min = distance[i];
                minIndex = i;
            }
        }
        // after this for loop we have the vertex with shortest distance from origin stored in minIndex and its distance stored in min
        visited[minIndex] = true;
        for (int i = 0; i < 9; i++)
        {
            if (graph[minIndex][i] > 0 && visited[i] == false && distance[i] > (distance[minIndex] + graph[minIndex][i]))
            {
                distance[i] = distance[minIndex] + graph[minIndex][i];
                parent[i] = minIndex;
            }
        }
    }
    printf("The shortest distances from source node are : \n");
    printf("Node 1 : %d\n", distance[0]);
    printf("Node 2 : %d\n", distance[1]);
    printf("Node 3 : %d\n", distance[2]);
    printf("Node 4 : %d\n", distance[3]);
    printf("Node 5 : %d\n", distance[4]);
    printf("Node 6 : %d\n", distance[5]);
    printf("Node 7 : %d\n", distance[6]);
    printf("Node 8 : %d\n", distance[7]);
    printf("Node 9 : %d\n", distance[8]);
}