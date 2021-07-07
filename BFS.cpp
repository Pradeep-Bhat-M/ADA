//Print all the nodes reachable from a given starting node in a digraph using BFS method.
#include<bits/stdc++.h>
using namespace std;
#define N 100

bool bfs(bool visit[N], int n, int v, int adj[N][N])
{
    queue<int> path;
    bool flag = false;
    int w;
    visit[v] = true;        // v -> starting vertex
    path.push(v);
    while(!path.empty())
    {
        for(w = 1; w <= n; w++)
        {                                              // 1 2 3
            if((adj[v][w] >= 1) && (!visit[w]))        // 0 1 10
            {                                          // 1 0 1
                visit[w] = true;                       // 10 1 0
                flag = true;
                cout << " " << w;                      //
                path.push(w);
            }
        }
        v = path.front();
        path.pop();
    }
    return flag;
}

// bool dfs(bool visit[N], int n, int v, int adj[N][N])
// {
//     stack<int> path;
//     bool flag = false;
//     int w;
//     visit[v] = true;
//     path.push(v);
//     while(!path.empty())
//     {
//         v = path.top();
//         path.pop();
//         for(w = 1; w <= n; w++)
//         {
//             if((adj[v][w] >= 1) && (!visit[w]))
//             {
//                 visit[w] = true;
//                 flag = true;
//                 cout << " " << w;
//                 path.push(w);
//             }
//         }
//     }
//     return flag;

// }


int main()
{
    int i, j, n, v;
    bool visit[N];
    int adj[N][N];

    cout << "\n Enter the no.of vertices: ";
    cin >> n;

    cout << "\n Enter adjacency matrix  : ";
    for(i = 1; i <= n; i++)
    {
      for(j = 1; j <= n; j++)
      {
          if(i == j)
            adj[i][j] = 0;
          else  
            adj[i][j] = 1;
      }
    }

    cout << "\n Enter the vertex no. to start with  : ";
    cin >> v;
    cout << "\n Reachability of vertex " << v << " : ";
    for(i = 1; i <= n; i++)
            visit[i] = false;

    if(!bfs(visit, n, v, adj))
        cout << "\n The vertex " << v << " has no reachability!! \n \n";

    return 0;
}