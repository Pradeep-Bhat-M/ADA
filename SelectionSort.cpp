#include <bits/stdc++.h>
#define N 100000
using namespace std;

void swap(int &a, int &b) 
{ 
    int temp = a; 
    a = b; 
    b = temp; 
} 
  
int selSort(int A[], int n) 
{ 
    int i, j, min, count = 0; 

    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++)
        {
            count++;
            if (A[j] < A[min]) 
                min = j; 
        } 
        swap(A[min], A[i]);
    } 
    return count;
} 
  
void display(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout << " " << A[i]; 
    cout << "\n"; 
} 
  
int main() 
{ 
    int n, count, A[N];
    clock_t stime, etime;

    cout << "\n Enter No. Of Elements : ";
    cin >> n;
    //cout << "\n Enter Array Elements to SORT : ";
    for(int i = 0; i < n; i++)
        A[i] = rand()%n;

    stime = clock();
    count = selSort(A, n); 
    etime = clock();
    cout << " Sorted Array : \n"; 
    display(A, n); 
    cout << "\n Time taken to sort "<< n <<" elements is %e "<< difftime(etime, stime);
    cout << "\n Number of steps taken to sort "<< n <<" elements is "<< count;

    return 0; 
} 
