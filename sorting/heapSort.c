#include <stdio.h>
#include<time.h>
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int N, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {

        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N){
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(){
    int size;
    int arr[]={15,19,13,2,1,16,29,34,59,92,123,9,11,23,456,8};
    size=sizeof(arr)/sizeof(arr[0]);
    printf("size is: %d",size);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    heapSort(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array is\n");
    printArray(arr, size);
    printf("\nCPU time used: %f seconds\n", cpu_time_used);
}
