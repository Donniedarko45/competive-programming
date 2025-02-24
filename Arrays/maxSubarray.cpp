// question 53
#include <bits/stdc++.h>
using namespace std;
int maxSubarray(vector<int> nums) {
  int maxi = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i; j < nums.size(); j++) {
      int sum = 0;
      for (int k = i; k < j; k++) {
        sum += nums[k];
        maxi = max(sum, maxi);
      }
    }
  }
  cout << maxi;
  return maxi;
}

// better solution
int bettermaxSubarray(vector<int> nums) {
  int maxi = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    int sum = 0;
    for (int j = i; j < nums.size(); j++) {
      sum += nums[j];
      maxi = max(sum, maxi);
    }
  }
  return maxi;
}
int main() {
  vector<int> nums;
  int num;
  int size;
  cout << "enter the size of an array: ";
  cin >> size;
  for (int i = 0; i < size; i++) {
    cin >> num;
    nums.push_back(num);
  }
  // maxSubarray(nums);
  bettermaxSubarray(nums);
}
