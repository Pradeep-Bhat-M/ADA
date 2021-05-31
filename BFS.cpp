//Print all the nodes reachable from a given starting node in a digraph using BFS method.

#include<bits/stdc++.h>
using namespace std;
#define N 100
// int queue[size],visit[20],rear=-1,front=0;
// int n,s,adj[20][20],flag=0;
// void insertq(int v)
// {
//     queue[++rear]=v;
// }

// int deleteq()
// {
//     return(queue[front++]);
// }

// int qempty()
// {

//   if(rear<front)
//     return 1;

//   else
//     return 0;
// }


bool bfs(bool visit[N], int n, int v, int adj[N][N])
{
    queue<int> path;
    bool flag = false;
    int w;
    visit[v] = true;
    path.push(v);
    //insertq(v);

    while(!path.empty())
    {
        v = path.front();
        path.pop();
        for(w = 1; w <= n; w++)
        {
            if((adj[v][w] >= 1) && (!visit[w]))
            {
                visit[w] = true;
                flag = true;
                cout << " " << w;
                path.push(w);
                //insertq(w);
            }
        }
    }
    return flag;
}

int main()
{
    int i, j, n, v;
    bool visit[N];
    cout << "\n Enter the no.of vertices: ";
    cin >> n;

    int adj[N][N];

    cout << "\n Enter adjacency matrix  : ";
    for(i = 1; i <= n; i++)
    {
      for(j = 1; j <= n; j++)
        cin >> adj[i][j];
    }
    cout << "\n Enter the start vertex  : \n";
    cin >> v;
    cout << "\n Reachability of vertex " << v << " : ";
    for(i = 1; i <= n; i++)
            visit[i] = false;

    if(!bfs(visit, n, v, adj))
        cout << "\n The vertex " << v << " has no reachability!! \n \n";

    return 0;
}