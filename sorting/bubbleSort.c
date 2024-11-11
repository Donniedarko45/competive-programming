#include <stdio.h>
#include<time.h>
void bubblesort(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int size;
    int arr[]={15,19,13,2,1,16,29,34,59,92,123,9,11,23,456,8};
    size=sizeof(arr)/sizeof(arr[0]);
    printf("size is: %d",size);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    bubblesort(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nCPU time used: %f seconds\n", cpu_time_used);
    return 0;
}