#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//brute force method...

int twiceNum(int arr[],int size){
 for(int i=0;i<size;i++){
   int count=0;
   int num=arr[i];
   for(int j=0;j<size;j++){
      if(arr[j]==num){
      count++;
    }
   }
    if(count==1){
      cout<<"num is: "<<arr[i];
      break;
   }
 }}

 //better solution..
int twiceBetterNum(int arr[],int size){
   int maxi=arr[0];
   for(int i=0;i<size;i++){
    maxi=max(maxi,arr[i]);
   }
   int hash[maxi]={0};
   for(int i=0;i<size;i++){
    hash[arr[i]]++;
   }

   for(int i=0;i<size;i++){
      if(hash[arr[i]]==1){
         cout<<arr[i];
      }
   
 }}  
 //suppose there is very long number take bigint like 10^12 we can't store it in hash so what we do we have to use map data structure

int usingMap(int arr[],int size){
   map<long,long>cont;
   for(int i=0;i<size;i++){
      cont[arr[i]]++;
   }
   for(auto it:cont){
      if(it.second==1){
         return it.first;
      }
   }
}

//every element appear twice use xor it will cancel of so use that

int betterNum(int arr[],int size){
   int xoR=0;
   for(int i=0;i<size;i++){
      xoR=xoR^arr[i];
   }
  cout<<xoR;

}

int main(){
   int size;
   cout<<"Enter the size of array: ";
   cin>>size;
   int arr[size];
   cout<<"put the value in an array "<<endl;
   for(int i=0;i<size;i++){
      cin>>arr[i];
   }
   //twiceBetterNum(arr,size);
  // twiceNum(arr,size);
  betterNum(arr,size);
}