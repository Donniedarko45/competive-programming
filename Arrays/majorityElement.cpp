//elements which appears more than n/2 times 166 no
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void majorityElement(vector<int>& nums) {
        int n =nums.size();
        map<int,int>arr;
        for(int i=0;i<n;i++){
            arr[nums[i]]++;
        }
        for(auto it : arr){
            if(it.second>n/2){
                cout<<it.first;
            }
        }
    }

// optimal solution..
int optimalMajorityElement(vector<int>nums){
    int count =0;
    int element;
    for(int i=0;i<nums.size();i++){
        if(count ==0){
            count = 1;
            element=nums[i];
        }
        else if(nums[i]==element){
            count ++;
        
        }else{
            count--;
        }
    }
    int finalCounter=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==element) finalCounter++;
    }
    if(finalCounter>(nums.size())){
      return element;
    }
    return -1;
}

int main(){
    vector<int>nums;
    int numberOfElements;
    cin>>numberOfElements;
    for(int i=0;i<numberOfElements;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    majorityElement(nums);
}