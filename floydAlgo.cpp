#include<bits/stdc++.h>
using namespace std;

void flyod(int **A, int n, int **C)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                if(A[i][k] != INT_MAX && A[k][j] != INT_MAX)
                    A[i][j] = A[i][j] < (A[i][k] + A[k][j]) ? A[i][j] : (A[i][k] + A[k][j]);
        }
    }

}

void print(int **A, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(A[i][j] == INT_MAX)
                std::cout << " INF";
            else
                std::cout << " " << A[i][j];
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

int main()
{
    int n, wt;

    std::cout << "\n Enter the number of vertices : ";
    cin >> n;

    int *A[n], *C[n];
    for(int i = 0; i < n; i++)
    {
        A[i]=new int[n];
        C[i]=new int[n];
    }

    std::cout << "\n Enter the Adjacency matrix (enter -1 if there is no edge):\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> wt;
            if(wt == -1)
                wt = INT_MAX;
            A[i][j] = wt;
        }
    }

    // clock_t start,end;
	// start=clock();
    flyod(A, n, C);
    // end=clock();
    std::cout << "\n Shortest distance b/w each pair of vertices : \n\n";
    print(A, n);


    // double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    // cout<<fixed<<setprecision(6)<<"\n\nTime taken: "<<time_taken<<"\n\n";

    return 0;

}