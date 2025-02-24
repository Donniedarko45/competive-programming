/*Longest subarray with sum k*/
#include <bits/stdc++.h>
using namespace std;

// brute force....
int linearSearch(vector<int> nums, int num) {
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == num) {
      return true;
    }
  }
  return num;
}

int longestConsecutiveSequence(vector<int> nums) {
  int count;
  int longest = 1;
  for (int i = 0; i < nums.size(); i++) {
    int x = nums[i];
    count = 1;
    while (linearSearch(nums, x + 1) == true) {
      x = x + 1;
      count++;
    }
  }
  cout << count;
  return count;
}

// better solution..
int betterLongestConsecutiveSequence(vector<int> nums) {
  // first sort..
  sort(nums.begin(), nums.end());

  int longest = 1, countCurrent = 0, lastSmaller = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] - 1 == lastSmaller) {
      countCurrent++;
      lastSmaller = nums[i];
    } else if (nums[i] != lastSmaller) {
      countCurrent = 1;
      lastSmaller = nums[i];
    }
    longest = max(longest, countCurrent);
  }
  cout << longest;
  return longest;
}
int main() {
  int n;
  cout << "Enter how many elements do you want in your array: ";
  cin >> n;
  vector<int> nums;
  int element;
  for (int i = 0; i < n; i++) {
    cin >> element;
    nums.push_back(element);
  }
  // longestConsecutiveSequence(nums);
  betterLongestConsecutiveSequence(nums);
}
