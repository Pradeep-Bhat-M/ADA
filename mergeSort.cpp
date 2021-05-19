#include <bits/stdc++.h>
#define N 100000
using namespace std;

void display(int A[N], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout << " " << A[i]; 
    cout << "\n"; 
}

void merge(int a[N], int n, int left, int mid, int right)
{
    int i, j, k, temp[right - left + 1];
    i = left;
    j = mid+1;
    k = 0;
    
    while(i <= mid && j <= right)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else 
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= right)
        temp[k++] = a[j++];

    for(i = left, j = 0; i <= right; i++)
        a[i] = temp[j++];
}

void mergeSort(int a[N], int n, int left, int right)
{
    if(left >= right)
        return;
    
    int mid = (left + right)/2;
    mergeSort(a, n, left, mid);
    mergeSort(a, n, mid+1, right);

    merge(a, n, left, mid, right);
}



int main() 
{   
    int n, A[N];
    clock_t stime, etime;

    cout << "\n Enter No. Of Elements : ";
    cin >> n;
    // cout << "\n Enter Array Elements to SORT : ";
    for(int i = 0; i < n; i++)
        A[i] = rand() % 100000;

    // pivot = A[0];
    stime = clock();
    mergeSort(A, n, 0, n-1); 
    etime = clock();
    if(n < 300)
    {
        cout << "\n Sorted Array : "; 
        display(A, n); 
    }
    else
        cout << "\n Array is sorted, but printing it won't make any difference.";

    cout << "\n Time taken to sort "<< n <<" elements is "<< difftime(etime, stime);
    // cout << "\n Number of steps taken to sort "<< n <<" elements is "<< count;

    return 0; 
}
