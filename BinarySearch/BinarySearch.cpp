#include "bits/stdc++.h"
#include <iostream>
using namespace std;

int IndexOfElement(int arr[], int size, int target) {
  int low = 0;
  int high = size - 1;
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] > target)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int IndexOfElementRecursive(int arr[], int size, int target, int low,
                            int high) {
  if (low > high)
    return -1;
  int mid = (low + high) / 2;
  if (arr[mid] == target)
    return mid;
  else if (target > arr[mid])
    return IndexOfElementRecursive(arr, size, 8, mid + 1, high);
  return IndexOfElementRecursive(arr, size, 8, low, mid - 1);
}
int main() {
  int target = 16;
  int arr[8] = {3, 4, 6, 7, 9, 12, 16, 17};
  cout << IndexOfElement(arr, 8, target);
}
