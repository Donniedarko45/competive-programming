#include <stdio.h>
#include <time.h>
void InsertionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            // Swap the elements
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main() {
    int size;
    int arr[]={1,9,11,15,17,25,59,69,83,113,256,452,512};
    size=sizeof(arr)/sizeof(arr[0]);
    printf("size is: %d",size);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    InsertionSort(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nCPU time used: %f seconds\n", cpu_time_used);
    return 0;
}
