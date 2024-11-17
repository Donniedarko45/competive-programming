/*Longest subarray with sum k*/
#include <bits/stdc++.h>
using namespace std;
// brute
int longestSubarray(int arr[], int n, int k) {
  int len = 0, j;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (j = i; j < n; j++) {
      sum += arr[j];
    }
    if (sum == k) {
      len = max(len, j - i + 1);
    }
  }
  cout << "length of max subarray with sum = k is : " << len;
  return len;
}
int main() {
  int n;
  cout << "enter the size of array: ";
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[n];
  }
  int k;
  cout << "enter the summation of max-subArray: ";
  cin >> k;
  longestSubarray(arr, n, k);
}
