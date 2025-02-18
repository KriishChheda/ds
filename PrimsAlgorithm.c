#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void prims(int graph[9][9]);
int main()
{
    int graph[9][9] = {
        {0, 4, 0, 0, 0, 0, 8, 0, 0},   // Node 0
        {4, 0, 8, 0, 0, 0, 0, 11, 0},  // Node 1
        {0, 8, 0, 7, 0, 0, 0, 2, 0},   // Node 2
        {0, 0, 7, 0, 9, 14, 0, 0, 0},  // Node 3
        {0, 0, 0, 9, 0, 10, 0, 0, 0},  // Node 4
        {0, 0, 0, 14, 10, 0, 2, 0, 0}, // Node 5
        {0, 0, 0, 0, 0, 2, 0, 1, 6},   // Node 6
        {8, 11, 2, 0, 0, 0, 1, 0, 7},  // Node 7
        {0, 0, 0, 0, 0, 0, 6, 7, 0}    // Node 8
    };
    prims(graph);
    return 0;
}
// currently we have created 5 nodes named 0,1,2,3,4 , shown their connections using the Adj matrix

void prims(int graph[9][9])
{
    // every node will have three data the parent node , the distance from the parent node and whether its visited or not . So i will create three arrays
    bool visited[9];
    int parent[9];
    int distance[9];
    // initially every single node has parent = NULL and distance = 0
    for (int i = 0; i < 9; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    // finally you select any one node as the root node and land on it. For simplicity i am taking node 0. The root node will not have a parent .
    distance[0] = 0;
    parent[0] = -1;
    // our shortest path shouold be ready in n-1 iterations if n is the no of nodes in the graph
    for (int count = 0; count < 9; count++)
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
        // at the end of this for loop we have our node with the smallest distance in minIndex along with that distance stored in min
        visited[minIndex] = true;
        for (int i = 0; i < 9; i++)
        {
            if (graph[minIndex][i] > 0 && visited[i] == false && distance[i] > graph[minIndex][i])
            {
                distance[i] = graph[minIndex][i];
                parent[i] = minIndex;
            }
        }
    }
    // Now after the for loop we have our parents and their respective childs , we can print them
    // i will print it in the format of parent - child     distance
    printf("Edge \tWeight\n");
    int sum = 0;
    for (int i = 1; i < 9; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
        sum = sum + graph[parent[i]][i];
    }
    printf("The total cost is : %d", sum);
}