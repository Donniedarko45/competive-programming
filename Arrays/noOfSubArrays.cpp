#include <iostream>
using namespace std;
// we have to count number of sub-arrays => if we xor the sub-array of all the
// elements from an sub-arrayy they will give sum as k..

int noOfSubArray(int arr[], int n, int m) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    int xoR = 0;
    for (int j = i; j < n; j++) {
      xoR = xoR ^ arr[j];
      if (xoR == m) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  int arr[5] = {4, 2, 2, 6, 4};
  cout << noOfSubArray(arr, 5, 6);
}
