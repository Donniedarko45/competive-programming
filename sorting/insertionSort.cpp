/*
? bubbleSort: adjacent swapping will be done
*/
#include <bits/stdc++.h>
using namespace std;
void InsertionSort(int arr[], int size) {
  for (int i = 0; i <= size; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
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
  InsertionSort(arr, size);
  cout << "Sorted array is: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
// worst case => O(n^2)
