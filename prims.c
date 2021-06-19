#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int V = 5;

void readGraph(int graph[V][V]) {
    printf("Enter the graph in matrix form\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++)
            scanf("%d",&graph[i][j]);
    }
}

int minKey(int key[], bool set[])
{
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (set[v] == false && key[v] < min) { 
            min = key[v];
            min_index = v;
        }
  
    return min_index;
}

int printMST(int parent[], int graph[V][V])
{
    int sum = 0;;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        sum = sum + graph[i][parent[i]];
    }
    printf("\n Weight of MST = %d", sum);
}

void prim(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool set[V];

    for(int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        set[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V - 1; count++) 
    {
        int u = minKey(key, set);

        set[u] = true;

        for (int v = 0; v < V; v++) 
        { 

            if(graph[u][v] && set[v] == false && graph[u][v] < key[v]) 
            { 
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}

int main() 
{
    printf("Enter the vertices in the graph : ");
    scanf("%d",&V);
    int graph[V][V];
    readGraph(graph);
    prim(graph);
    return 0;
}