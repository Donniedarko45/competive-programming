// in an array of 0 and 1's find maximum consecutive ones
#include<bits/stdc++.h>
using namespace std;
int maximumConsecutiveOnes(int arr[],int size){
  int maxi,count=0;
  for(int i=0;i<size;i++){
    if(arr[i]==1){
        count++;
        maxi=max(maxi,count);
    }else{
        count=0;
    }
  }
}
int main(){
     int size1;
   cout << "Enter the size of array: ";
   cin >> size1;
   int arr[size1];
   for(int i=0;i<size1;i++){
      cin>>arr[i];
   }
}