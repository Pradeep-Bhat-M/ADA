#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

void swap(int &a, int &b) 
{ 
    int temp = a; 
    a = b; 
    b = temp; 
} 

void minHeapify(int arr[], int n, int i){
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;
    int smallest = i;
    if (left < n && arr[smallest] > arr[left])
        smallest = left;
    if (right < n && arr[smallest] > arr[right])
        smallest = right;
    if (smallest != i) {
        int tmp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = tmp;
        minHeapify(arr,n,smallest);
    }
}

void heapSort(int arr[], int n){
	for (int i = n/2 - 1; i >= 0; i--){
		minHeapify(arr, n, i);
    }
	for (int i = n - 1; i >= 0; i--) {
        //this_thread::sleep_for(std::chrono::milliseconds(1));
		swap(arr[0], arr[i]);
		minHeapify(arr, i, 0);
	}
}

void printArray(int arr[], int n){
	for (int i = 0; i <n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(){
    srand(time(0));
    int range;
    printf("Enter number of elements : ");
    scanf("%d", &range);
    int n = range; //size of array
    int arr[n];
    for(int i=0; i<n; i++){
        arr[i] = rand()%(10 * n);
    }
    printf("Before sorting \n");
    printArray(arr,n);
    
    printf("For %d array size", n);

    time_t start, end;
    time(&start);
    heapSort(arr, n);
    time(&end);

    printf("\nSorted array is \n");
    printArray(arr, n);
    double time_taken = (double)(end - start);
    printf("time taken is %lds", time_taken);
    
}
