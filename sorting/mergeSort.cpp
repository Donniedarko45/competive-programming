#include <bits/stdc++.h>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
  cout << "hello";
  vector<int> temp;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
    cout << arr[i] << " ";
  }
}

void ms(vector<int> &arr, int low, int high) {
  if (low <= high)
    return;

  cout << "inside first fxn hello";
  int mid = (low + high) / 2;
  ms(arr, low, mid);
  ms(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n) {
  cout << "inside first fxn hello";
  ms(arr, 0, n - 1); // n will be initial size of an array
}

int main() {
  vector<int> arr = {2, 8, 6, 8, 4, 2, 0, 5};
  int n = arr.size();
  cout << n;
  mergeSort(arr, n);
}
