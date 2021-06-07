#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest;
    int wt;
    struct Edge *next;
};

struct Graph {
    int v, e;
    struct Edge *edges;
};

void insertEdges(struct Graph *graph) {

    printf("Enter the initial, terminal and weights of the edges %d\n", graph -> e);
    for(int i = 0; i < graph -> e; i++) {

        int w;
        struct Edge *new = (struct Edge*)malloc(sizeof(struct Edge));
        printf("For edge %d : ", ( i + 1));
        scanf("%d",&new->src);
        scanf("%d",&new->dest);
        scanf("%d",&w);
        new -> wt = w;
        if(graph -> edges == NULL) { 
            graph -> edges = new;
            graph -> edges -> next = NULL;
        }
        else if(graph -> edges -> wt >= new -> wt) {
           new -> next = graph -> edges;
           graph -> edges = new;
        }
        else {
            struct Edge *tmp = graph -> edges;
            while(tmp -> next != NULL && tmp -> next -> wt < new -> wt) {
                tmp = tmp -> next;
            }
            new -> next = tmp -> next;
            tmp -> next = new;
        }
    }
}

void createGraph(struct Graph *graph) {
    printf("Enter the vertices and edges in the graph : ");
    scanf("%d %d", &graph -> v, &graph -> e);
    insertEdges(graph);
}

int hasCycle(struct Graph *graph) {
    int check[graph -> v];
    for(int i = 0; i < graph -> v; i++)
        check[i] = -1;
    int count = 0;
    struct Edge *tmp = graph -> edges;
    while(count < (graph -> e))
    {
        int is = tmp -> src;
        int id = tmp -> dest;
        while(check[is] != -1) { 
            is = check[is];
        }
        while(check[id] != -1) { 
            id = check[id];
        }
        if(is != id) 
        {
            check[id] = is;
            count++;
        }
        else 
        {
            return 0;
        }
        tmp = tmp -> next;
    }
    return 1;
}

int main() 
{
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    createGraph(graph);
    int flag = hasCycle(graph);
    if(flag)
        printf("\n Graph has no cycle");
    else
        printf("\n Graph has cycle");
    return 0;

}