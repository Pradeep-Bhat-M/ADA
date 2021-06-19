#include <bits/stdc++.h>
#define N 64
using namespace std;

void matrixMul(int a[][N], int b[][N], int result[][N], int n)
{
    for(int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {  
            result[i][k] = 0;
            for (int j = 0; j < n; j++)
            {
                result[i][k] += a[i][j] * b[j][k];
            }
        }
    } 
    //return result;
}

void printMatrix(int matrix[][N], int n)
{
    cout << "\n The resultant is Matrix : ";
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        for (int j = 0; j < n; j++)
            cout << " " << matrix[i][j];
    } 
}

int main()
{
    cout << "\n Matrix Multiplication";
    int n = 2;
    int a[][N] = {{1, 2}, {3, 1}};
    int b[][N] = {{5, 6}, {7, 8}};
    int res[N][N];
    matrixMul(a, b, res, n);
    printMatrix(res, n);
    
    return 0;
}