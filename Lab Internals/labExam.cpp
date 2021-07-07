#include <bits/stdc++.h> // Quick Sort;
#define N 100

using namespace std;

int partition(int a[], int n, int left, int right, int pivot)
{
    int leftPartition = left + 1;
    int rightPartition = right;

    while(true)
    {
        while(a[leftPartition] < pivot)
            leftPartition++;
        
        while(a[rightPartition] > pivot)
            rightPartition--;
        
        if(leftPartition >= rightPartition)
            break;
        else
            swap(a[leftPartition], a[rightPartition]);
    }
    swap(a[rightPartition], a[left]);

    return rightPartition;    
}

void quickSort(int a[], int n, int left, int right)
{
    if(left >= right)
        return;

    int cross, pivot = a[left];
    cross = partition(a, n, left, right, pivot);
    quickSort(a, n, left, cross - 1);
    quickSort(a, n, cross + 1, right);

}

void display(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout << " " << a[i];
}

int main()
{
    int n, a[N];
    cout << "\n Enter no. of elements : ";
    cin >> n;
    cout << "\n Enter elements : ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        //a[i] = rand() % (n * 10);
    }

    quickSort(a, n, 0, n-1);
    cout << "\n Sorted Array : ";
    display(a, n);

    return 0;
}