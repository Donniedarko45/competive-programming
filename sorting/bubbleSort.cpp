/*
? bubbleSort: adjacent swapping will be done
*/
#include <bits/stdc++.h>
using namespace std;
// timeComplexity:->O(n^2) in worst case but for best case it is => O(n)
void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

// second method.. without bool

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
  cout << "Enter the size of the array: ";
  cin >> size;
  int arr[size];
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  bubblesort(arr, size);

  cout << "Sorted array is: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
