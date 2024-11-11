#include<bits/stdc++.h>
using namespace std;
// brute force method..
int twoSum(int arr[],int size,int target){
   for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if(arr[i]+arr[j]==target){
            cout<<"element is at posistion: "<<i<<","<<j ;
        }
    }
   }
}

// Better method=>we use hashmap...
int twoSumBetter(int arr[],int size,int target){
   // done on leetcode https://leetcode.com/problems/two-sum/description/
}

// here we are using extra space by using hashmap so we can optimise more by two pointer approach 

int twoSumOptimal(int arr[],int size,int target){
  //https://www.naukri.com/code360/problems/reading_6845742?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=SUBMISSION
}
int main(){
    int size;
    cout<<"enter the size of your array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];  
    }
    int target;
    cout<<"Enter the targeted sum: ";
    cin>>target;
    twoSum(arr,size,target);
  //twoSumOptimal(arr,size,target);
    
}