#include <bits/stdc++.h>
#define N 10000
using namespace std;

void swap(int &a, int &b) 
{ 
    int temp = a; 
    a = b; 
    b = temp; 
} 

void display(int A[N], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout << " " << A[i]; 
    cout << "\n"; 
}

int partition(int A[N], int n, int left, int right, int pivot) 
{
   int low = left;
   int high = right - 1;

   while(true) 
   {
        while(A[low] < pivot)  // 1 5 7 2 6
            low++;
        
        while(high > 0 && A[high] > pivot) 
            high--;

        if(low >= high)
            break;
        else 
            swap(A[low], A[high]);
   }
   swap(A[low], A[right]);
//    cout << "\n Pivot Element : " << pivot;
//    cout << "\n Updated Array : "; 
//    display(A, n);
   return low;
}

void quickSort(int A[N], int n, int left, int right) 
{
   if(right-left <= 0) 
      return;   
   else 
   {
      int pivot = A[right];
      int cross = partition(A, n, left, right, pivot);
      quickSort(A, n, left, cross-1);
      quickSort(A, n, cross+1, right);
   }        
}

int main() 
{ 
    int n, A[N];
    //clock_t stime, etime;

    cout << "\n Enter No. Of Elements : ";
    cin >> n;
    //cout << "\n Enter Array Elements to SORT : ";
    for(int i = 0; i < n; i++)
    {
        //cin >> A[i];
        A[i] = rand()%n;
    }

    //pivot = A[0];
    //stime = clock();
    quickSort(A, n, 0, n-1); 
    //etime = clock();
    cout << " Sorted Array : "; 
    display(A, n); 
    //cout << "\n Time taken to sort "<< n <<" elements is "<< difftime(etime, stime);
    //cout << "\n Number of steps taken to sort "<< n <<" elements is "<< count;

    return 0; 
} 