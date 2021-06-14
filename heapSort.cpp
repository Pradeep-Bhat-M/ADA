#include <bits/stdc++.h>
using namespace std;
#define N 1000
  
int count = 0;

void heapify(int arr[], int n, int i) 
{
    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
  
    if (leftChild < n && arr[leftChild] > arr[max])
      max = leftChild;
  
    if (rightChild < n && arr[rightChild] > arr[max])
      max = rightChild;
  
    if (max != i) 
    {
        ::count++;
        swap(arr[i], arr[max]);
        heapify(arr, n, max); 
    }
  }
  
void heapSort(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) 
    {
        ::count++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
  
void display(int arr[], int n) 
{
    for (int i = 0; i < n; ++i)
      cout << " " << arr[i];
    cout << "\n";
}
  
int main() 
{ 
    int n, A[N];
    //clock_t stime, etime;

    cout << "\n Enter No. Of Elements : ";
    cin >> n;
    //cout << " Enter Array Elements to SORT : ";
    for(int i = 0; i < n; i++)
    {
        //cin >> A[i];
        A[i] = rand()%n;
    }

    //pivot = A[0];
    //stime = clock();
    heapSort(A, n); 
    //etime = clock();
    cout << " Sorted Array :"; 
    //display(A, n); 
    //cout << "\n Time taken to sort "<< n <<" elements is "<< difftime(etime, stime);
    cout << "\n Number of steps taken to sort "<< n <<" elements is "<< ::count;

    return 0; 
} 

