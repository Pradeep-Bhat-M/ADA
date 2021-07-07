#include <iostream>
#include <stdio.h>
#include <cmath>
#define N 100
long int count = 0, sol = 0;
using namespace std;

void printBoard(int a[N], int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(a[i] == j)
                cout << " Q";
            else
                cout << " *";
        }
        cout << "\n";
    }
    cout << "-------------------------------------------\n";
}

bool validMoveChecker(int a[N], int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        count++;
        if (a[j] == i || (std::abs(a[j] - i) == std::abs(j - k)))
           return false;
    }
    return true;
}

void nQueen(int a[N], int k, int n)
{ 
    for (int i = 1; i <= n; i++)
    {
        if (validMoveChecker(a, k, i))
        {
            a[k] = i;
            if (k == n)
                //printBoard(a, n);
                sol++;
            else
                nQueen(a, k + 1, n);
        }
    }
}

int main()
{
    int a[N], n;
    cout << "\n Enter the Board Size : ";
    cin >> n;
    // n = 4;   
    cout << "-------------------------------------------\n";
    nQueen(a, 1, n);   
    cout<<"\n Count = "<<count << "\n";
    cout<< "\n No. of possible solutions = " << sol;
    return 0;
}