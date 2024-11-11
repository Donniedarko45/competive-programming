#include<bits/stdc++.h>
using namespace std;

int leadersArray(vector<int>nums){
     //optimal solution..
      int maxi=INT_MIN;
      vector<int>ans;
      //we are running loop from backwards and updating the maxi if the iterator is greater than that
      for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]>maxi){
           maxi = nums[i];
           ans.push_back(nums[i]);
        }
      }
     for(auto it: ans){
        cout<<it<<" ";
     }
   }
int main(){
  vector<int>nums;
  int num;
  int size;
  cout<<"enter the size of an array: ";
  cin>>size;
  for(int i=0;i<size;i++){
    cin>>num;
    nums.push_back(num);
  }
  leadersArray(nums);
}