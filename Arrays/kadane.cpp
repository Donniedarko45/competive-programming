// maximum subarray sum....

#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int subArrayMax(vector<int> arr) {
  int maxi = INT_MIN;
  int len = arr.size();
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j++) {
      int sum = 0;
      for (int k = i; k < j; k++) {
        sum = sum + arr[k];
        maxi = max(sum, maxi);
      }
    }
  }
  cout << maxi;
  return maxi;
}

// what is better subArrayMax

int bettersubArraySum(vector<int> arr) {
  int maxi = INT_MIN;
  int len = arr.size();
  for (int i = 0; i < len; i++) {
    int sum = 0;
    for (int j = i; j < len; j++) {
      sum += arr[j];
      maxi = max(sum, maxi);
    }
  }
  cout << maxi;
  return maxi;
}

// kadane algorithm

int optimisedBettersoln(vector<int> arr) {
  int maxi = INT_MIN;
  int sum = 0;
  int len = arr.size();
  for (int i = 0; i < len; i++) {
    sum += arr[i];
    if (sum > maxi) {
      maxi = sum;
    }
    if (sum < 0) {
      sum = 0;
      return {};
    }
  }
  return maxi;
}

int main() {
  vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
  //  subArrayMax(arr);
  bettersubArraySum(arr);
}
