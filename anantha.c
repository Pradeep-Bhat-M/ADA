#include <stdio.h>
int a[10][10], vis[10], n;

void bfs(int v)
{
    int q[10], f = 0, r = 0, u, i, j;
    vis[v] = 1;
    q[r] = v;
    while (f <= r)
    {
        u = q[f];
        printf("% d\t", u);
        for (i = 1; i <= n; i++)
        {
            if (a[u][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                r = r + 1;
                q[r] = i;
            }
        }
        f++;
    }
    printf("\n");
}

void bfsSearch(int src) {
    printf("\n Connected graphs : ");
    bfs(src);
    for (int u = 0; u < n; u++)
    {
        if (vis[u] == 0)
        bfs(u);
    }  
}


void main()
{
    int i, j, src;
    printf("\nenter the no of vertices:\t");
    scanf("%d", &n);
    printf("\nenter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    printf("\nenter the source node:\t");
    scanf("%d", &src);
    printf("nodes reachable from % d vertex is ", src);
    bfsSearch(src);
}