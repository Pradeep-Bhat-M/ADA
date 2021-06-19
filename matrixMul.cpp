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

void fillMatrix(int a[][N], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = rand()%10;
}

int main()
{
    int n;
    cout << "\n Enter the size for Matrices : ";
    cin >> n;
    int a[N][N], b[N][N];
    int res[N][N];

    fillMatrix(a, n);
    fillMatrix(b, n);    
    matrixMul(a, b, res, n);
    printMatrix(res, n);
    return 0;
}